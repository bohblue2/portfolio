import time
import queue
import threading
import configparser

from loguru import logger
from datrobo.util.telegram_api import Telegram

from datrobo.client.execution.agent.hrp.hrp import (
    HrpAgent
)

from dattoolbox.research.hrp.sample import (
    HRP_Sample
)

from datrobo.client.logic.main_logic import (
    HRP_Stable,
    HRP_Neutral,
    HRP_Active
)

from datrobo.client.execution.model.krx import (
    VirtualModelKRX
)

DEBUG = False
DEBUG_MP = False

def run_model(DEBUG=False, DEBUG_MP=False):
    if DEBUG:
        # 디버깅용 공인인증서 비밀번호, 계좌번호, 등 설정파일
        CONFIG_FILE_PATH = "c:/config/config_debug.ini"

        if DEBUG_MP:
            HRP_STABLE_MODEL_PORTFOLIO  = HRP_Sample
            HRP_NEUTRAL_MODEL_PORTFOLIO = HRP_Sample
            HRP_ACTIVE_MODEL_PORTFOLIO  = HRP_Sample
        else:
            HRP_STABLE_MODEL_PORTFOLIO  = HRP_Stable
            HRP_NEUTRAL_MODEL_PORTFOLIO = HRP_Neutral
            HRP_ACTIVE_MODEL_PORTFOLIO  = HRP_Active
    else:
        # 실 운용 공인인증서 비밀번호, 계좌번호, 등 설정파일
        CONFIG_FILE_PATH = "c:/config/config.ini"

        HRP_STABLE_MODEL_PORTFOLIO  = HRP_Stable
        HRP_NEUTRAL_MODEL_PORTFOLIO = HRP_Neutral
        HRP_ACTIVE_MODEL_PORTFOLIO  = HRP_Active

    config = configparser.ConfigParser()
    config.sections()
    config.read(CONFIG_FILE_PATH)
    telegram = Telegram(*[
        config["TELEGRAM"]["token"],
        config["TELEGRAM"]["chat_id"]
    ])

    WORLD_MODEL_ID          = "KRX_ID"
    WORLD_MODEL_NAME        = "KRX"

    HRP_STABLE_ACCOUNT_NUM  = config['ACCOUNT_NUM']['hrp_stable']
    HRP_NEUTRAL_ACCOUNT_NUM = config['ACCOUNT_NUM']['hrp_neutral']
    HRP_ACTIVE_ACCOUNT_NUM  = config['ACCOUNT_NUM']['hrp_active']

    HRP_AGENT_CLASS         = HrpAgent

    HRP_MUTEX               = threading.Lock()

    HRP_STABLE_EVENT_QUEUE  = queue.Queue()
    HRP_NEUTRAL_EVENT_QUEUE = queue.Queue()
    HRP_ACTIVE_EVENT_QUEUE  = queue.Queue()

    agents = {
        'HRP_STABLE': {
            "agent"       : HRP_AGENT_CLASS,
            "agent_args"  : {
                "unique_id"         : "hrp_stable",
                "account_num"       : HRP_STABLE_ACCOUNT_NUM,
                "model_portfolio"   : HRP_STABLE_MODEL_PORTFOLIO,
                "mutex"             : HRP_MUTEX,
                "event_queue"       : HRP_STABLE_EVENT_QUEUE,
                "config_file_path"  : CONFIG_FILE_PATH
            }
        },
        'HRP_NEUTRAL': {
            "agent"       : HRP_AGENT_CLASS,
            "agent_args"  : {
                "unique_id"         : "hrp_neutral",
                "account_num"       : HRP_NEUTRAL_ACCOUNT_NUM,
                "model_portfolio"   : HRP_NEUTRAL_MODEL_PORTFOLIO,
                "mutex"             : HRP_MUTEX,
                "event_queue"       : HRP_NEUTRAL_EVENT_QUEUE,
                "config_file_path"  : CONFIG_FILE_PATH
            },
        },
        'HRP_ACTIVE': {
            "agent"     : HRP_AGENT_CLASS,
            "agent_args": {
                "unique_id"         : "hrp_active",
                "account_num"       : HRP_ACTIVE_ACCOUNT_NUM,
                "model_portfolio"   : HRP_ACTIVE_MODEL_PORTFOLIO,
                "mutex"             : HRP_MUTEX,
                "event_queue"       : HRP_ACTIVE_EVENT_QUEUE,
                "config_file_path"  : CONFIG_FILE_PATH
            }
        }
    }

    MockKRX = VirtualModelKRX(WORLD_MODEL_ID, WORLD_MODEL_NAME)
    MockKRX.add_agent(agents)

    logger.info("{} 월드 모델 초기화 완료.". format(WORLD_MODEL_NAME))
    for agent_key, agent in agents.items():
        logger.info("{}가 {} 월드 모델에 추가됨".format(
            agent['agent_args']['unique_id'],
            WORLD_MODEL_NAME
        ))

    telegram.send_message("{} 월드 모델 초기화 완료. 주문 집행 모듈 시작.".format(
        WORLD_MODEL_NAME
    ))

    while True:
        MockKRX.step()
        time.sleep(1)

if __name__ == "__main__":
    run_model(DEBUG=DEBUG, DEBUG_MP=DEBUG_MP)
