##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################

from abc import (
    ABCMeta,
    abstractmethod,
    abstractclassmethod,
    abstractstaticmethod
)
import json
import time
import asyncio

import qrcode
import websockets
#from auth import auth
from loguru import logger

from .controller import Controller

DEBUG = True

class IKiwoomServer():
    __metaclass__ = ABCMeta

# KiwoomServer 과 mng 를 합쳐야됨
class KiwoomServer(IKiwoomServer):
    def __init__(self, port, company_name):
        #self._auth = auth.Authentication(db_path="./db", company_name=company_name)
        self._port = port
        self._host = '0.0.0.0'
        self._api_controller = Controller()
        logger.add("system.log", rotation="100 MB")

    def run_server(self):
        print(f"Server is running at [ ws://{self._host}:{self._port} ]")
        start_server = websockets.serve(self._server, self._host, self._port)
        loop = asyncio.get_event_loop()
        loop.run_until_complete(start_server)
        loop.run_forever()

    @staticmethod
    async def _send_message(websocket, msg: str):
        msg = {'data': msg}
        msg = json.dumps(msg)
        logger.info("_send_message: " + msg)
        await websocket.send(msg)

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
            return {"msg": result}
        return ""

    def _generate_user(self, user_id):
        return self._auth.generate(user_id)

    def _send_command_get_message(self, msg):
        self._api_controller.run_command(msg)
        return self._api_controller.get_message()

    async def _get_broadcast(self, websocket):
        while True:
            data = await self._api_controller.get_broadcast()
            if data != "":
                await KiwoomServer._send_broadcast(websocket, data)
            else:
                await asyncio.sleep(1)

    async def _get_run_command(self, websocket):
        while True:
            data = await websocket.recv()
            result = await self._run_command(data)
            await KiwoomServer._send_message(websocket, result)

    async def _server(self, websocket, path):
        if not DEBUG:
            await KiwoomServer._send_message(websocket, "Initializing...")
            time.sleep(1)
            await KiwoomServer._send_message(websocket, "ID:")
            user_id = await websocket.recv()
            time.sleep(1)
            await KiwoomServer._send_message(websocket, "TOKEN:")
            token = await websocket.recv()
            auth_result = self._auth.verify(user_id, token)
            if not auth_result:
                return
        # greeting = f"{'*' * 15} * WELCOME * {'*' * 15}"
        # await KiwoomServer._send_message(websocket, greeting)
        fts = [
            asyncio.ensure_future(self._get_broadcast(websocket)),
            asyncio.ensure_future(self._get_run_command(websocket))
        ]
        for f in asyncio.as_completed(fts):
            try:
                x = await f
                print(x)
            except:
                print("one Connection closed")

# Simple Test Code
if __name__ == "__main__":
    server = KiwoomServer()
    _, url = server._generate_user("hehpollon")
    qrcode.make(url).show()
