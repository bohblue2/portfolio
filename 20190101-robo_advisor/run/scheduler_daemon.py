# -*- codings : utf-8 -*-
import os
import datetime
import configparser
import time
import pytz
from datrobo.client.common.database import Database
from datrobo.util.telegram_api import Telegram
from loguru import logger
from apscheduler.schedulers.background import BackgroundScheduler
from apscheduler.events import EVENT_JOB_EXECUTED, EVENT_JOB_MISSED, EVENT_JOB_ERROR
from global_value import CONFIG_FILE_PATH

KEY_RUN_SERVER = "run_server"
KEY_RCV_DATE = "rcv_data"
KEY_RUN_MNG = "run_mng"
KEY_RUN_EXECUTION = "run_execution"

KEY_TIME = "t"
KEY_FILE_PATH = "fp"

DEFAULT_MARKET_START_TIME = "09:00:00"
DEFAULT_MARKET_END_TIME = "15:30:00"

sched = None


def send_to_telegram(msg):
	config = configparser.ConfigParser()
	config.sections()
	config.read(CONFIG_FILE_PATH)

	telegram = Telegram(*[
		config["TELEGRAM"]["token"],
		config["TELEGRAM"]["chat_id"]
	])

	cur_time = datetime.datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
	telegram.send_message(cur_time + " " + msg)
	telegram.send_message("exit_telegram_thread")


def run_cron(file_path):
	try:
		os.startfile(file_path)
		msg = "스케줄러가 프로그램을 실행 (Path: {0})".format(file_path)
		logger.info(msg)
		send_to_telegram(msg)
	except Exception as e:
		logger.exception(str(e))
		send_to_telegram("스케줄러가 프로그램을 실행하다 예외 발생 (Path: {0})".format(file_path))


def cron_event_listener(event):
	if event.exception:
		msg = "Scheduler Daemon에서 작업 실행중 예외 발생"
		logger.exception(msg)
		send_to_telegram(msg)

	else:
		global sched

		if EVENT_JOB_EXECUTED == event.code:
			logger.info("EVENT_JOB_EXECUTED")

		elif EVENT_JOB_MISSED == event.code:
			now = datetime.datetime.now() + datetime.timedelta(seconds=5)
			job = sched.get_job(event.job_id)
			msg = "Scheduler Daemon에서 작업 실행중 Missing 발생. 5초 후 재실행 (Path: {0})".format(job.args[0])
			logger.error(msg)
			send_to_telegram(msg)

			new_job = sched.add_job(
				job.func_ref,
				"cron",
				hour=now.hour,
				minute=now.minute,
				second=now.second,
				args=job.args
			)
			logger.info(new_job)

		elif EVENT_JOB_ERROR == event.code:
			job = sched.get_job(event.job_id)
			msg = "Scheduler Daemon에서 작업 실행중 Error 발생 (Path: {0})".format(job.args[0])
			logger.error(msg)
			send_to_telegram(msg)


def main():
	st_date = datetime.date.today()

	logger.add("log/{time:YYYYMMDD}_scheduler_daemon.log", encoding="utf-8")
	cur_date = datetime.datetime.now().strftime("%Y-%m-%d")
	cur_week = datetime.datetime.today().weekday()

	if 5 == cur_week or 6 == cur_week:
		logger.info("주말엔 Scheduler Daemon을 돌리지 않는다.")

		while st_date == datetime.date.today():
			time.sleep(3600)

		return

	global sched
	sched = BackgroundScheduler(timezone=pytz.timezone("Asia/Seoul"))
	sched.add_listener(cron_event_listener, EVENT_JOB_EXECUTED | EVENT_JOB_MISSED | EVENT_JOB_ERROR)
	sched.start()

	# 프로그램 실행 정보
	run_infos = {
		KEY_RUN_SERVER: {
			KEY_TIME: datetime.datetime.combine(datetime.date.today(), datetime.time(8, 40, 0)),
			KEY_FILE_PATH: "batch_start.bat",
		},
		KEY_RUN_EXECUTION: {
			KEY_TIME: datetime.datetime.combine(datetime.date.today(), datetime.time(8, 40, 0)),
			KEY_FILE_PATH: "run_execution.bat",
		},
		KEY_RCV_DATE: {
			KEY_TIME: datetime.datetime.combine(datetime.date.today(), datetime.time(10, 0, 0)),
			KEY_FILE_PATH: "rcv_data_run.bat",
		},
		KEY_RUN_MNG: {
			KEY_TIME: datetime.datetime.combine(datetime.date.today(), datetime.time(16, 10, 0)),
			KEY_FILE_PATH: "manage_run.bat",
		},
	}

	with Database(CONFIG_FILE_PATH) as db:
		holiday_info = db.select_holiday_info(cur_date)

		if 1 == holiday_info["cnt"]:
			msg = "프로그램을 실행시키지 않는다. [사유: {0}]".format(holiday_info["comment"])
			logger.info(msg)
			send_to_telegram(msg)

			while st_date == datetime.date.today():
				time.sleep(3600)

			return

		mk_delay_info = db.get_market_delay_sec(cur_date, DEFAULT_MARKET_START_TIME, DEFAULT_MARKET_END_TIME)

		if 1 == mk_delay_info["cnt"]:
			delay_open = mk_delay_info["st_delay_sec"]
			delay_close = mk_delay_info["ed_delay_sec"]

			run_infos[KEY_RUN_SERVER][KEY_TIME] = run_infos[KEY_RUN_SERVER][KEY_TIME] + datetime.timedelta(seconds=delay_open)
			run_infos[KEY_RCV_DATE][KEY_TIME] = run_infos[KEY_RCV_DATE][KEY_TIME] + datetime.timedelta(seconds=delay_open)
			run_infos[KEY_RUN_EXECUTION][KEY_TIME] = run_infos[KEY_RUN_EXECUTION][KEY_TIME] + datetime.timedelta(seconds=delay_open)
			run_infos[KEY_RUN_MNG][KEY_TIME] = run_infos[KEY_RUN_MNG][KEY_TIME] + datetime.timedelta(seconds=delay_close)

			msg = "프로그램들의 실행 시간을 조절한다.\n사유: {0}\n서버시작: {1}\n데이터수신: {2}\n관리수신: {3}".format(
				mk_delay_info["comment"],
				run_infos[KEY_RUN_SERVER][KEY_TIME].strftime("%H:%M:%S"),
				run_infos[KEY_RUN_EXECUTION][KEY_TIME].strftime("%H:%M:%S"),
				run_infos[KEY_RCV_DATE][KEY_TIME].strftime("%H:%M:%S"),
				run_infos[KEY_RUN_MNG][KEY_TIME].strftime("%H:%M:%S"),
			)
			logger.info(msg)
			send_to_telegram(msg)

	logger.info("Scheduler Daemon 시작")

	for _, run_info in run_infos.items():
		run_time = run_info[KEY_TIME]

		job = sched.add_job(
			run_cron,
			"cron",
			hour=run_time.hour,
			minute=run_time.minute,
			second=run_time.second,
			args=(run_info[KEY_FILE_PATH],)
		)
		logger.info(job)

	while st_date == datetime.date.today():
		time.sleep(3600)

	sched.remove_all_jobs()


if __name__ == "__main__":
	print("\n")
	print(" #######        ##     ##########    ########     ######   ########     ######      ##")
	print(" ##     ##    ##  ##       ##        ##      ## ##      ## ##      ## ##      ##    ##")
	print(" ##      ##  ##    ##      ##        ##      ## ##      ## ##      ## ##      ##    ##")
	print(" ##      ## ##      ##     ##        ########   ##      ## ########   ##      ##    ##")
	print(" ##      ## ##########     ##        ##     ##  ##      ## ##      ## ##      ##    ##")
	print(" ##     ##  ##      ##     ##        ##      ## ##      ## ##      ## ##      ##    ##")
	print(" ######     ##      ##     ##        ##      ##   ######   ########     ######      ##")
	print("\n")

	time.sleep(1)

	main()

	time.sleep(30)

	logger.info("날짜 변경으로 인하여 10분뒤에 재부팅 합니다.\n취소하려면 명령 프롬프트에서 shutdown -a를 입력하세요.")
	os.system("shutdown -r -t 600")  # 날짜가 바뀌면 재부팅
