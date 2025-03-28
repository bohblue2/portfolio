##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################

from pywinauto import application as pyapplication
from pywinauto import timings
from datrobo.util.cipher_mng import Aes256Cipher
from datrobo.util.telegram_api import Telegram
from global_value import CONFIG_FILE_PATH
import configparser
import time
import datetime
import os
import win32com.client

"""
    1. 번개3 설치
    2. 종료시 팝업 설정 해제
"""


def get_process_list():
    """
    윈도우에서 떠있는 프로세스 리스트를 가져온다

    :return: 프로세스명 리스트 (list)
    """
    ret = []
    wmi = win32com.client.GetObject('winmgmts:')
    processes = wmi.instancesOf('Win32_Process')

    for process in processes:
        ret.append(process.Properties_('Name').Value)

    return ret


def check_update():
    # 번개 3가 이미 켜져 있으면 종료
    proc_list = get_process_list()

    if "nkmini.exe" in proc_list:
        os.system("taskkill /im nkmini.exe")
        time.sleep(10)

    app = pyapplication.Application()
    app.start("C:/KiwoomFlash3/bin/nkministarter.exe")

    title = "번개3 Login"
    dlg = timings.wait_until_passes(20, 0.5, lambda: app.window(title=title))

    config = configparser.ConfigParser()
    config.sections()
    config.read(CONFIG_FILE_PATH)

    aes256cipher = Aes256Cipher()
    f = open(config['AES']['key_path'], "r")
    aeskey = f.readline()
    f.close()

    time.sleep(2)

    pass_ctrl = dlg.Edit2
    pass_ctrl.set_focus()
    pass_ctrl.type_keys(aes256cipher.decrypt_str(config['KIWOOM']['pass'], aeskey))

    cert_ctrl = dlg.Edit3
    cert_ctrl.set_focus()
    cert_ctrl.type_keys(aes256cipher.decrypt_str(config['KIWOOM']['cert_pass'], aeskey))

    btn_ctrl = dlg.Button0
    btn_ctrl.click()

    st_time = time.time()
    timeout_sec = 60 * 10

    telegram = Telegram(*[
        config['TELEGRAM']['token'],
        config['TELEGRAM']['chat_id']
    ])

    while True:
        time.sleep(5)
        proc_list = get_process_list()

        if "nkmini.exe" in proc_list:
            break

        if time.time() - st_time > timeout_sec:
            cur_time = datetime.datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
            telegram.send_message("{0} 번개3가 정상적으로 실행되지 않았습니다.".format(cur_time))
            return

    time.sleep(10)
    # 환경설정 메뉴를 선택한 후 ‘번개3 종료시 종료확인창 보기’
    # 체크 박스의 체크를 해제
    os.system("taskkill /im nkmini.exe")
