# Global Multi Asset Robo Advisor
[Introduction](https://yb98.notion.site/2018-ETF-1c1cd80736dc80778804d8182cddaa17?pvs=4)

## 필수
- 키움 OPEN API 설치
## 설치
- 개발하는 PC에서 설치
```commandline
python setup.py develop
```
- 개발하는 PC에서 삭제
```commandline
python setup.py develop --uninstall
```
- 운영하는 PC에서 설치
```commandline
python setup.py install
```
## 실행
- 스케줄러 데몬
>1. 32bit python3로 실행시켜야됨 (관리자권한 terminal)
>2. run/scheduler_deamon.py 실행
- 서버
>1. 32bit python3로 실행시켜야됨 (관리자권한 terminal)
>2. run/start.py 실행시 websocket 서버 실행
- 데이터 수신기
>1. run/run_rcv_data.py 실행
- 관리
>1. run/run_manage.py 실행
## 주의사항
- 새로운 패키지 추가시 setup.py의 install_requires에 추가 바랍니다.
## aeskey.txt 파일 생성 방법
```commandline
from datrobo.util.cipher_mng import Aes256Cipher
aes = Aes256Cipher()
aes.make_key_file()
```
## 암호화
```commandline
from datrobo.util.cipher_mng import Aes256Cipher
aes = Aes256Cipher()
print(aes.encrypt_str(평문문자열, 생성된키값))
```
