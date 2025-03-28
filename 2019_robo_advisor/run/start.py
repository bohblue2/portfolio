##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################

from datrobo.server.kw_server import Server
from datrobo.server.api.api_controller import *
from loguru import logger
from global_value import CONFIG_FILE_PATH


def update_module():
    # pywinauto conflict with qt
    from datrobo.server import update
    update.check_update()


if __name__ == '__main__':
    logger.add("log/{time:YYYYMMDD}_server.log", rotation="100 MB")
    #update_module()
    api_controller = ApiController()
    server = Server(port=8765, api_instance=api_controller, config_file_path=CONFIG_FILE_PATH, company_name="DAT")
    server.run_server()
