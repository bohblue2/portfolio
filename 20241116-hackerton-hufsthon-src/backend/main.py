from datetime import datetime 
from fastapi import Body, FastAPI, Depends, HTTPException, Path, Query
from fastapi.middleware.cors import CORSMiddleware
from hufsthon.schemas import ChatCompletionResponse, ChatRequest, HealthCheck, RoleEnum
from hufsthon.service.llm import LlmService

from dotenv import load_dotenv

from hufsthon.vectorstore import get_client, get_consultation_collection
load_dotenv('.dev.env')

LATEST_INDEX = -1

def get_app() -> FastAPI:
    app = FastAPI()

    # Add CORS middleware
    app.add_middleware(
        CORSMiddleware,
        allow_origins=["*"],  # In production, replace with specific origins
        allow_credentials=True,
        allow_methods=["*"],
        allow_headers=["*"],
    )
    
    return app  

def get_llm_service():
    client = get_client()
    collection = get_consultation_collection()
    service = LlmService(collection)
    # TODO: Implement service router?k
    try:
        yield service
    finally:
        service.close()


app = get_app()

@app.get(
    "/health", 
    response_model=HealthCheck,
    summary="서버 상태 확인",
    description="서버의 현재 상태와 타임스탬프를 반환합니다.",
    responses={
        200: {
            "description": "서버가 정상적으로 동작 중",
            "content": {
                "application/json": {
                    "example": {
                        "status": "healthy",
                        "timestamp": "2024-01-01T00:00:00"
                    }
                }
            }
        }
    }
)
async def health_check() -> HealthCheck:
    return HealthCheck(
        status="healthy",
        timestamp=datetime.now()
    )

@app.post(
    "/api/chat/completion", 
    response_model=ChatCompletionResponse
)
async def chat_completion(
    llm_service: LlmService = Depends(get_llm_service),    
    request: ChatRequest = Body(
        ...,
        example={
            "model": "gpt-4o",
            "messages": [
                {
                    "role": "user",
                    "content": "Hello, how are you?"
                },
                {
                    "role": "assistant",
                    "content": "I'm fine, thank you."
                }
            ]
        }
    )
):
    last_message = request.messages[LATEST_INDEX].content
    response_text = llm_service.generate_answer(content=last_message)
    if response_text == "" or response_text is None:
        response_text = "I'm sorry, I don't have an answer to that question."
    return ChatCompletionResponse(role=RoleEnum.assistant, content=response_text)

@app.get(
    "/recommendation/asks",
    summary="추천 질문 목록 조회",
    description="자주 묻는 추천 질문 목록을 반환합니다. 질문 개수는 쿼리 파라미터로 지정할 수 있습니다.",
    responses={
        200: {
            "description": "추천 질문 목록 반환 성공",
            "content": {
                "application/json": {
                    "example": {
                        "questions": [
                            {
                                "title": "역사",
                                "content": "한국외대의 역사는 어떻게 되나요?"
                            }
                        ]
                    }
                }
            }
        }
    }
)
async def get_recommended_questions(
    k: int = Query(
        default=3,
        description="반환할 추천 질문의 개수",
        ge=1,
        le=10
    )
) -> dict:
    recommended_questions = [
        {
            "id": 1,
            "title": "정신건강",
            "content": "정신건강 상담을 받는 것이 취업에 불이익이 될 수 있나요?"
        },
        {
            "id": 2,
            "title": "상담방식",
            "content": "포근이와의 대화는 어떻게 저장되고 관리되나요?"
        },
        {
            "id": 3,
            "title": "전문의연계",
            "content": "위급상황시 어떤 방식으로 전문가 상담이 연결되나요?"
        },
        {
            "id": 4,
            "title": "개인맞춤",
            "content": "개인 맞춤형 답변을 위해 어떤 정보가 필요한가요?"
        },
        {
            "id": 5,
            "title": "정보신뢰성",
            "content": "포근이가 제공하는 정보는 어떤 기관의 데이터를 기반으로 하나요?"
        }
    ]
    
    return {
        "questions": recommended_questions[:min(k, len(recommended_questions))]
    }

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8080)