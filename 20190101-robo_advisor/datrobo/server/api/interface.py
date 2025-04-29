##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################

from typing import Union


class ApiInterface:
    def run_command(self, command: str):
        raise NotImplementedError

    def get_message(self) -> Union[str, dict]:
        raise NotImplementedError

    def get_broadcast(self) -> Union[str, dict]:
        raise NotImplementedError
