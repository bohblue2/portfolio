import threading
import time
import telegram
from queue import Queue


class Telegram:
    def __init__(self, token, chat_id):
        self.message_queue = Queue()
        self.thread = threading.Thread(
            target=self._request_send_message,
            args=(token, chat_id, self.message_queue,)
        )
        self.thread.start()

    def send_message(self, text):
        self.message_queue.put(str(text))

    @staticmethod
    def _request_send_message(token, chat_id, message_queue: Queue):
        bot = telegram.Bot(token=token)
        while True:
            text = message_queue.get()
            if text == "exit_telegram_thread":
                break
            try:
                if "img_path:" in text:
                    image_path = text.split(":")[1]
                    bot.sendPhoto(chat_id=chat_id, photo=open(image_path, "rb"))
                else:
                    bot.sendMessage(chat_id=chat_id, text=str(text))
                time.sleep(1)  # telegram bot limit
            except Exception as e:
                print(e)
