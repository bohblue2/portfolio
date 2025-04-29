
import json
from pathlib import Path
from pprint import pprint
from langchain_openai import OpenAIEmbeddings
import json
import glob
import os
from typing import List, Dict
from langchain_text_splitters import RecursiveCharacterTextSplitter
from tqdm import tqdm

from hufsthon.constant import TRAINING_LABEL_DATA_PATH, VALIDATION_LABEL_DATA_PATH
from hufsthon.vectorstore import create_index, get_client, get_consultation_collection

def load_json_files(directory: str) -> List[Dict]:
    all_data = []
    json_files = glob.glob(os.path.join(directory, "*.json"))
    
    for file_path in tqdm(json_files, desc="Loading JSON files"):
        data = {}

        file_name = os.path.splitext(os.path.basename(file_path))[0]
        data['doc_id'] = file_name 
        with open(file_path, 'r', encoding='utf-8') as f:
            data['json_data'] = json.loads(f.read())
        all_data.append(data)
    return all_data

def prepare_vector_data(data: List[Dict], embedding_model: OpenAIEmbeddings) -> List[Dict]:
    """데이터를 벡터 저장소 형식으로 변환"""
    vector_data = []
    
    text_splitter = RecursiveCharacterTextSplitter(
        chunk_size=1500,
        chunk_overlap=150,
        length_function=len,
        is_separator_regex=False,
    )

    for item in tqdm(data, desc="Preparing vector data"):
        content = json.dumps(item['json_data'], ensure_ascii=False)
        doc_id = item['doc_id']
        idx = 1
        texts = text_splitter.create_documents([content])
        for text in texts:
            vector_data.append({
                "doc_id": int(f"{int(doc_id) + idx * 100_000}"),
                "content": text.page_content,
                "content_embedding": embedding_model.embed_query(text.page_content),
                "created_at": "",
                "modified_at": ""
            })
            idx += 1 
    return vector_data

if __name__ == "__main__":
    embedding = OpenAIEmbeddings(model="text-embedding-3-large")
    
    client = get_client()
    if client.has_collection("consultation_cases"):
        client.drop_collection("consultation_cases")
    collection = get_consultation_collection()
    create_index(collection)

    for dir in [VALIDATION_LABEL_DATA_PATH, TRAINING_LABEL_DATA_PATH]:
        json_data = load_json_files(dir)
        vector_data = prepare_vector_data(json_data[:1], embedding)
        vector_data = [doc for doc in vector_data if doc['content_embedding'] is not None]
        collection.insert(vector_data)
