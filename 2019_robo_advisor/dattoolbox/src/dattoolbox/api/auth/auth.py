##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################

import os
from threading import Lock

import pyotp
from tinydb import (
    TinyDB,
    Query
)

class Authentication:
    """
    Authentication with OTP (TOTP, HOTP). Thread safe.
    """
    def __init__(self, db_path: str, company_name: str):
        """
        :param db_path: Database path where user name and secret key stored.
        :param company_name: company name that issue otp.
        """
        os.makedirs(db_path, exist_ok=True)
        self._db = TinyDB(f"{db_path}/db.json")
        self._table = self._db.table('users')
        self._item = Query()
        self._lock = Lock()
        self._company_name = company_name
        self._prev_success_token = dict()

    def generate(self, user_id: str, algorithm: str = 'TOTP') -> (str, str):
        """
        Generate user otp with given algorithm.

        :param user_id: User ID
        :param algorithm: `TOTP` or `HOTP`
        :return: (secret key, provisioning_url(for google OTP))
        """
        self._lock.acquire()
        try:
            secret_key = pyotp.random_base32()
            if self._check_exists(user_id):
                return '', ''
            if algorithm == 'TOTP':
                provisioning_uri = pyotp.totp.TOTP(secret_key).provisioning_uri(
                    user_id, issuer_name=self._company_name)
            elif algorithm == 'HOTP':
                provisioning_uri = pyotp.hotp.HOTP(secret_key).provisioning_uri(
                    user_id, issuer_name=self._company_name)
            else:
                return '', ''

            self._set_secret_key(user_id, secret_key, algorithm)
            return secret_key, provisioning_uri
        finally:
            self._lock.release()

    def verify(self, user_id: str, otp_value: str, algorithm: str = 'TOTP',  counter: int = 0) -> bool:
        """
        Verify otp value.

        :param user_id: USER ID
        :param algorithm: `TOTP` or `HOTP`
        :param otp_value: otp value to verify
        :param counter: used for HOTP
        :return: is verified
        """
        self._lock.acquire()
        try:
            if not self._check_exists(user_id):
                return False
            secret_key = self._get_secret_key(user_id)
            if algorithm == 'TOTP':
                otp = pyotp.TOTP(secret_key)
                result = otp.verify(otp_value)
            elif algorithm == 'HOTP':
                otp = pyotp.HOTP(secret_key)
                result = otp.verify(otp_value, counter=int(counter))
            else:
                return False

            # Reject re-verify with same token
            if self._prev_success_token.get('user_id', '') is otp_value:
                return False

            if result is True:
                self._prev_success_token['user_id'] = otp_value
            return result
        finally:
            self._lock.release()

    def _get_secret_key(self, user_id: str) -> str:
        res = self._table.search(self._item.id == user_id)
        return res[0]['key']

    def _check_exists(self, user_id: str) -> bool:
        res = self._table.search(self._item.id == user_id)
        return True if res else False

    def _set_secret_key(self, user_id: str, secret_key: str, otp_type: str) -> None:
        self._table.insert({'id': user_id, 'key': secret_key, 'type': otp_type})
