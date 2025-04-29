# -*- coding: utf-8 -*-
from Crypto import Random
from Crypto.Cipher import AES

import json
import hashlib
import base64
import logging


class Aes256Cipher:
	"""
	AES256 암/복호화 클래스
	"""

	@classmethod
	def gen_key(cls):
		"""
		무작위로 AesKey를 생성한다.

		:return: Base64로 인코딩된 암호화키 (str)
		"""
		rand_val = Random.new().read(AES.key_size[-1])
		temp = hashlib.sha256(rand_val).digest()
		temp = base64.b64encode(temp).decode("ascii")
		return temp

	def make_key_file(self):
		"""
		aeskey.txt 파일을 생성
		"""
		aeskey = self.gen_key()

		with open("aeskey.txt", mode="w", encoding="utf-8") as f:
			f.write(aeskey)

	def encrypt_dict(self, dict_obj, key, charset="utf-8"):
		"""
		Dictionary를 Aes256(CBC)로 암호화한다.

		:param dict_obj: 암호화할 대상 (dict)
		:param key: gen_key()로 생성된 암호화키 (str)
		:param charset: Character Set (str)
		:return: 성공시 Base64로 인코딩된 암호화값 (String) / 실패시 None
		"""
		ret = None

		if type(dict_obj) is dict:
			try:
				json_text = json.dumps(dict_obj)
				ret = self.encrypt_str(json_text, key, charset)
			except Exception as e:
				logging.error(e)

		return ret

	@classmethod
	def encrypt_str(cls, plain_text, key, charset="utf-8"):
		"""
		String을 Aes256(CBC)로 암호화한다.

		:param plain_text: 암호화할 대상 (str)
		:param key: gen_key()로 생성된 암호화키 (str)
		:param charset: Character Set (str)
		:return: 성공시 Base64로 인코딩된 암호화값 (str) / 실패시 None
		"""
		cipher = None

		try:
			key = base64.b64decode(key.encode("ascii"))
			iv = Random.new().read(AES.block_size)
			temp = plain_text.encode(charset)
			temp = base64.b64encode(temp)
			temp = cls._padding(temp)
			encryptor = AES.new(key, AES.MODE_CBC, IV=iv)
			cipher = iv + encryptor.encrypt(temp)
			cipher = base64.b64encode(cipher).decode("ascii")
		except Exception as e:
			logging.error(e)

		return cipher

	def decrypt_dict(self, cipher, key, charset="utf-8"):
		"""
		Aes256(CBC)로 복호화하여 Dictionary로 리턴한다.

		:param cipher: 복호화할 대상 (str)
		:param key: gen_key()로 생성된 암호화키 (str)
		:param charset: Character Set (str)
		:return: 성공시 복호화된 Dictionary (dict) / 실패시 None
		"""
		ret = None

		try:
			plain_text = self.decrypt_str(cipher, key, charset)
			ret = json.loads(plain_text, encoding=charset)
		except Exception as e:
			logging.error(e)

		return ret

	@classmethod
	def decrypt_str(cls, cipher, key, charset="utf-8"):
		"""
		Aes256(CBC)로 복호화하여 String으로 리턴한다.

		:param cipher: 복호화할 대상 (str)
		:param key: gen_key()로 생성된 암호화키 (str)
		:param charset: Character Set (str)
		:return: 성공시 복호화된 문자열 (str) / 실패시 None
		"""
		plain = None

		try:
			cipher = base64.b64decode(cipher.encode("ascii"))
			key = base64.b64decode(key.encode("ascii"))
			iv = cipher[0:AES.block_size]
			cipher_body = cipher[AES.block_size:]

			encryptor = AES.new(key, AES.MODE_CBC, IV=iv)
			temp = encryptor.decrypt(cipher_body)
			temp = cls._unpadding(temp)
			temp = base64.b64decode(temp)
			plain = temp.decode(charset)
		except Exception as e:
			logging.error(e)

		return plain

	@classmethod
	def _padding(cls, plain):
		"""
		Base64로 인코딩된 값에 Padding을 넣는다. (공백으로 채움)

		:param plain: 원본 (bytes)
		:return: Padding된 값 (bytes)
		"""
		ret = plain

		if 0 != len(plain) % AES.block_size:
			length = AES.block_size - (len(plain) % AES.block_size)
			ret = plain + b' ' * length

		return ret

	@classmethod
	def _unpadding(cls, plain):
		"""
		Base64로 인코딩된 값의 패딩을 지운다 (공백을 지움)

		:param plain: 원본 (bytes)
		:return: Unpadding된 값 (bytes)
		"""
		return plain.decode("ascii").strip().encode("ascii")
