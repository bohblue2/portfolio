# -*- coding: utf-8 -*-
from setuptools import setup

install_requires = [
	"numpy==1.16.4",
	"pandas==0.24.2",
	"PyQt5==5.12.2",
	"pymysql==0.9.3",
	"websockets==7.0",
	"websocket-client==0.56.0",
	"apscheduler==3.6",
	"pycryptodome==3.6.6",
	"loguru==0.2.5",
	"pyotp==2.2.7",
	"qrcode==6.1",
	"tinydb==3.13.0",
	"scipy==1.3.0",
	"sqlalchemy==1.3.5",
	"matplotlib==3.1.1",
	"pywinauto==0.6.7",
	"mesa==0.8.6",
	"python-telegram-bot==11.1.0",
	"retrying==1.3.3",
	"DBUtils==1.3",
]

packages = [
	"datrobo",
	"datrobo.util",
	"datrobo.server",
	"datrobo.server.api",
	"datrobo.server.auth",
	"datrobo.client",
	"datrobo.client.common",
	"datrobo.client.data_mng",
	"datrobo.client.execution",
	"datrobo.client.execution.agent",
	"datrobo.client.execution.agent.hrp",
	"datrobo.client.execution.model",
	"datrobo.client.execution.model.krx",
	"datrobo.client.execution.strategy",
	"datrobo.client.execution.strategy.hrp",
	"datrobo.client.logic",
	"datrobo.client.manage_account",
]

setup(
	name="datrobo",
	version="1.0.0",
	author="dat",
	description="DAT ROBO 1",
	install_requires=install_requires,
	packages=packages,
	package_dir={"datrobo": "datrobo"},
)
