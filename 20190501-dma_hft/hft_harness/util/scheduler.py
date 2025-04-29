# -*- codings : utf-8 -*-
from apscheduler.schedulers.background import BackgroundScheduler
from apscheduler.jobstores.base import JobLookupError
import time
import pytz

class Scheduler:

    # 클래스 생성시 스케쥴러 데몬을 생성합니다.
    def __init__(self):
        job_defaults = {
            'coalesce': False,
            'max_instances': 3
        }
        tz = pytz.timezone('Asia/Seoul')
        self.sched = BackgroundScheduler(job_defaults=job_defaults, timezone=tz)
        self.sched.start()
        self.job_id=''

    # 클래스가 종료될때, 모든 job들을 종료시켜줍니다.
    def __del__(self):
        self.shutdown()

    # 모든 job들을 종료시켜주는 함수입니다.
    def shutdown(self):
        self.sched.shutdown()

    # 모든 job을 종료시켜줍니다.
    def remove_all_scheduler(self):
        self.sched.remove_all_jobs()

    # 특정 job을 종료시켜줍니다.
    def stop_scheduler(self, job_id):
        try:
            self.sched.remove_job(job_id)
        except JobLookupError as err:
            print("fail to stop scheduler: %s" % err)
            return

    # 특정 job을 수정합니다.
    def modify_scheduler(self, job_id, arg):
        try:
            self.sched.modify_job(job_id, args=arg)
            print("%s scheduler is modified" % job_id)
        except JobLookupError as err:
            print("fail to modify scheduler: %s" % err)
            return

    def hello(self, type, job_id):
        print("%s scheduler process_id[%s] : %d" % (type, job_id, time.localtime().tm_sec))

    def interval_scheduler(self, func, job_id, time, args=None):
        '''
        :param func: 실행할 함수
        :param job_id: job id (str)
        :param time: time interval (int)
        :param args: func이 요구하는 Arguments
        :return:
        '''
        try:
            print("%s Scheduler Start" % 'interval')
            self.sched.add_job(func, 'interval', minutes=time, id=job_id, args=args)
            return True
        except Exception as e:
            print("Error : %s" % str(e))
            return False

    def cron_scheduler(self, func, job_id, time, args=None):
        '''

        :param func: 실행할 함수
        :param job_id: job id (str)
        :param time: Scheduler가 실행되어야 할 특정 시간(dict) [hour, min, sec]
            time ={
                'hour' : '23' # 0-23
                'min' : '56' # 0-59
                'sec' : '28' # 0-59
            }
        :param args: func이 요구하는 Arguments
        :return:
        '''
        try:
            print("%s Scheduler Start" % 'cron')
            self.sched.add_job(func, 'cron', day_of_week='mon-sun', \
                               hour=time['hour'], minute=time['min'], second=time['sec'], \
                               id=job_id, args=args)
            return True
        except Exception as e:
            print("Error : %s" % str(e))
            return False
