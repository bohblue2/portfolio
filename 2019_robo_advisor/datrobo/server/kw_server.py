##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################

from datrobo.server.auth import auth
import websockets
import time
import asyncio
import json
import qrcode
from loguru import logger
import datetime
from datrobo.util.telegram_api import Telegram
import configparser

DEBUG = False


class Server:
    def __init__(self, port, api_instance, config_file_path, company_name):
        self._auth = auth.Authentication(db_path="./db", company_name=company_name)
        self._port = port
        self._host = '0.0.0.0'
        self._api_instance = api_instance
        config = configparser.ConfigParser()
        config.sections()
        config.read(config_file_path)
        self.telegram = Telegram(*[
            config['TELEGRAM']['token'],
            config['TELEGRAM']['chat_id']
        ])
        pass

    def __del__(self):
        self.telegram.send_message("exit_telegram_thread")

    def run_server(self):
        logger.info(f"Server is running at [ ws://{self._host}:{self._port} ]")
        start_server = websockets.serve(self._server, self._host, self._port)
        loop = asyncio.get_event_loop()
        loop.run_until_complete(start_server)
        cur_time = datetime.datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
        self.telegram.send_message(f"{cur_time} DAT ROBO 서버 가동")
        loop.run_forever()

    @staticmethod
    async def _send_message(websocket, msg):
        msg_json = {'data': msg}
        msg_str = json.dumps(msg_json)

        if dict == type(msg) and "req_cmd" in msg:
            main_cmd = msg["req_cmd"].split(" ")[0]

            if "get_stock_daily_chart" != main_cmd \
                    and "get_stock_daily_trend" != main_cmd \
                    and "get_stock_min_chart" != main_cmd:
                logger.info("_send_message: " + msg_str)

        else:
            logger.info("_send_message: " + msg_str)

        await websocket.send(msg_str)

    @staticmethod
    async def _send_broadcast(websocket, msg: str):
        msg = {'broadcast': msg}
        msg = json.dumps(msg)
        logger.info("_send_broadcast: " + msg)
        await websocket.send(msg)

    async def _run_command(self, msg):
        if len(msg) > 0:
            logger.info("_run_command: " + msg)
            result = self._send_command_get_message(msg)

            if type(result) is dict and "msg" in result:
                return result
            else:
                return {"msg": result}
        return ""

    def _generate_user(self, user_id):
        return self._auth.generate(user_id)

    def _send_command_get_message(self, msg):
        self._api_instance.run_command(msg)
        return self._api_instance.get_message()

    async def _get_broadcast(self, websocket):
        while True:
            data = await self._api_instance.get_broadcast()
            if data != "":
                await Server._send_broadcast(websocket, data)
            else:
                await asyncio.sleep(1)

    async def _get_run_command(self, websocket):
        while True:
            data = await websocket.recv()
            result = await self._run_command(data)
            await Server._send_message(websocket, result)

    async def _server(self, websocket, path):
        remote_addr = websocket.remote_address[0]
        if not DEBUG and "127.0.0.1" != remote_addr:
            await Server._send_message(websocket, "Initializing...")
            time.sleep(1)
            await Server._send_message(websocket, "ID:")
            user_id = await websocket.recv()
            time.sleep(1)
            await Server._send_message(websocket, "TOKEN:")
            token = await websocket.recv()
            auth_result = self._auth.verify(user_id, token)
            if not auth_result:
                return
        greeting = f"{'*' * 15} * WELCOME * {'*' * 15}"
        await Server._send_message(websocket, greeting)
        fts = [
            asyncio.ensure_future(self._get_broadcast(websocket)),
            asyncio.ensure_future(self._get_run_command(websocket))
        ]
        for f in asyncio.as_completed(fts):
            try:
                x = await f
                logger.info(x)
            except:
                logger.info("one Connection closed")


if __name__ == "__main__":
    server = Server()
    _, url = server._generate_user("hehpollon")
    qrcode.make(url).show()

