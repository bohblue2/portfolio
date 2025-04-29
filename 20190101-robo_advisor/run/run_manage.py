from datrobo.client.manage_account.manage import Manage
from datrobo.client.common.database import Database
from global_value import CONFIG_FILE_PATH
from datrobo.client.manage_account.report import Report

with Database(CONFIG_FILE_PATH) as db:
    account_list = ['5225431710', '5257021710', '5257022310']
    manage = Manage(db=db, account_list=account_list, config_file_path=CONFIG_FILE_PATH)
    try:
        ws = manage.connect()
        manage.insert_balance(ws)
        manage.insert_balance_detail(ws)
        manage.insert_trade(ws)
        manage.insert_complete()

        # 운용 시작하면 주석 해제
        for account in ['5225431710']: # 적극 투자만 표시
            report = Report(db, account, start_date='20190805', config_file_path = "C:\\config\\config.ini")  # 운용 시작일
            report.create_report()
            report.create_detail_report()
            del report
    except Exception as e:
        print("* Exception", e)
    finally:
        print("websocket closed")
        ws.close()
        del manage
