##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################
import pymysql.cursors
import configparser
import datetime
from DBUtils.SteadyDB import connect
from datrobo.util.cipher_mng import Aes256Cipher


class Database:
    def __init__(self, config_file_path):
        self.config_file_path = config_file_path

    def __enter__(self):
        config = configparser.ConfigParser()
        config.sections()
        config.read(self.config_file_path)

        aes256cipher = Aes256Cipher()
        f = open(config['AES']['key_path'], "r")
        aeskey = f.readline()
        f.close()

        host = aes256cipher.decrypt_str(config['DATABASE']['host'], aeskey)
        port = int(aes256cipher.decrypt_str(config['DATABASE']['port'], aeskey))
        user = aes256cipher.decrypt_str(config['DATABASE']['user'], aeskey)
        password = aes256cipher.decrypt_str(config['DATABASE']['password'], aeskey)
        db = aes256cipher.decrypt_str(config['DATABASE']['db'], aeskey)

        # Connect to the database
        self.connection = connect(
            creator=pymysql,
            host=host,
            user=user,
            password=password,
            db=db,
            port=port,
            charset='utf8mb4',
            cursorclass=pymysql.cursors.DictCursor)
        return self

    def __exit__(self, exception_type, exception_val, trace):
        # Close connection to the database
        self.connection.close()

    def _execute_many_to_db(self, sql: str, data: list) -> None:
        with self.connection.cursor() as cursor:
            cursor.executemany(sql, data)
        self.connection.commit()

    def show_tables(self):
        with self.connection.cursor() as cursor:
            sql = "DESC balance"
            cursor.execute(sql, ())
            rows = cursor.fetchall()
            print(rows)
            return rows

    def insert_balance(self, data: tuple):
        with self.connection.cursor() as cursor:
            sql = "INSERT IGNORE INTO `balance` (`account`, `date`, `total_purchage_amount`, " \
                  "`total_evaluation_amount`, `total_evaluation_profit`, `total_profit_ratio`, " \
                  "`presume_deposit_asset`) VALUES (%s, %s, %s, %s, %s, %s, %s)"
            cursor.execute(sql, data)
        self.connection.commit()

    def insert_balance_detail(self, data: tuple):
        with self.connection.cursor() as cursor:
            sql = "INSERT IGNORE INTO `balance_detail` (`account`, `date`, `total_net_asset_early`, " \
                  "`total_net_asset_late`, `evaluate_profit`, `profit_ratio`, " \
                  "`turnover`) VALUES (%s, %s, %s, %s, %s, %s, %s)"
            cursor.execute(sql, data)
        self.connection.commit()

    def insert_balance_stock(self, data: tuple):
        with self.connection.cursor() as cursor:
            sql = "INSERT IGNORE INTO `balance_stock` (`account`, `date`, `stock_num`, " \
                  "`stock_name`, `evaluate_profit`, `profit_ratio`, `bought_price`, `cur_price`, " \
                  "`possess_amount`, `evaluate_price`, `possess_weight`) VALUES " \
                  "(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"
            cursor.execute(sql, data)
        self.connection.commit()

    def insert_trade(self, data: tuple):
        with self.connection.cursor() as cursor:
            sql = "INSERT IGNORE INTO `trade` (`account`, `date`, `order_num`, " \
                  "`stock_num`, `trade_gubun`, `order_kind_gubun`, `order_amount`, `order_price`, " \
                  "`fill_num`, `fill_amount`, `fill_price`, `fill_time`) VALUES " \
                  "(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"
            cursor.execute(sql, data)
        self.connection.commit()

    def insert_complete(self, data: tuple):
        with self.connection.cursor() as cursor:
            sql = "INSERT IGNORE INTO `complete_manage` (`date`, `is_complete`) VALUES " \
                  "(%s, %s)"
            cursor.execute(sql, data)
        self.connection.commit()

    def insert_daily_candle(self, data: list) -> None:
        sql = "INSERT IGNORE INTO " \
              "`kiwoom_day_candle` " \
              "(`shtcode`, `date`, `open_prc`, `high_prc`, `low_prc`, " \
              "`close_prc`, `bclose_prc`, `volume`, `trd_value`, `adj_flag`, " \
              "`adj_rate`) " \
              "VALUES " \
              "(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s);"
        self._execute_many_to_db(sql, data)

    def insert_daily_trend(self, data: list) -> None:
        sql = "INSERT IGNORE INTO " \
              "`kiwoom_trd_trends` " \
              "(`shtcode`, `date`, " \
              "`idv_buy`, `idv_sell`, `ist_buy`, `ist_sell`, `frg_buy`, `frg_sell`, " \
              "`ivt_buy`, `ivt_sell`, `psf_buy`, `psf_sell`) " \
              "VALUES " \
              "(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s);"
        self._execute_many_to_db(sql, data)

    def insert_code_master(self, data: list) -> None:
        with self.connection.cursor() as cursor:
            cur_date = datetime.date.today()
            sql = "INSERT INTO `code_master` " \
                  "(`shtcode`, `name`, `listing_date`, `last_update`) VALUES " \
                  "(%s, %s, %s, '{0}') " \
                  "ON DUPLICATE KEY UPDATE `name`=VALUES(`name`), `last_update`=VALUES(`last_update`);".format(cur_date)
            cursor.executemany(sql, data)

        self.connection.commit()

    def insert_weight(self, table: str, data: list) -> None:
        with self.connection.cursor() as cursor:
            sql = "INSERT IGNORE INTO " \
                  "`{}` " \
                  "(`date`, `shtcode`, `shtname`, `target_weight`, `target_quantity`, " \
                  "`current_weight`, `exec_success`, `rebal_decision`) " \
                  "VALUES " \
                  "(%s, %s, %s, %s, %s, %s, %s, %s);".format(table)
            cursor.execute(sql, data)

        self.connection.commit()


    def update_unfilled_trd_stock(self, table: str, data: list) -> None:
        with self.connection.cursor() as cursor:
            sql = "UPDATE `{}` " \
                  "SET `exec_success` = %s, `current_weight` = %s " \
                  "WHERE `date` = %s AND `shtcode` = %s".format(table)

            cursor.execute(sql, data)

        self.connection.commit()

    def select_holiday_tables(self, st_date: str, ed_date: str) -> list:
        with self.connection.cursor() as cursor:
            sql = "SELECT DATE_FORMAT(`date`, '%Y%m%d') AS holiday FROM holiday_table"
            extend_sql = []

            if st_date is not None:
                extend_sql.append("'{0}' <= `date`".format(st_date))

            if ed_date is not None:
                if 0 < len(extend_sql):
                    extend_sql.append("AND")

                extend_sql.append("`date` <= '{0}'".format(ed_date))

            if 0 < len(extend_sql):
                sql = sql + " WHERE " + " ".join(extend_sql)

            sql = sql + ";"

            cursor.execute(sql)
            rs = cursor.fetchall()

            ret = []
            for row in rs:
                ret.append(row["holiday"])

            return ret

    def select_holiday_info(self, date: str) -> dict:
        with self.connection.cursor() as cursor:
            sql = "SELECT COUNT(*) AS cnt, IFNULL(comment, '') AS cmt " \
                  "FROM holiday_table WHERE `date` = '{0}' LIMIT 1;".format(date)

            cursor.execute(sql)
            rs = cursor.fetchone()
            ret = {
                "cnt": rs["cnt"],
                "comment": rs["cmt"],
            }

            return ret

    def select_spc_trd_times(self, st_date: str, ed_date: str) -> list:
        with self.connection.cursor() as cursor:
            sql = "SELECT " \
                  "DATE_FORMAT(`date`, '%Y%m%d') AS spc_date, DATE_FORMAT(`mk_open`, '%H%i%s') AS mk_open, " \
                  "DATE_FORMAT(`mk_close`, '%H%i%s') AS mk_close " \
                  "FROM spc_trd_time"
            extend_sql = []

            if st_date is not None:
                extend_sql.append("'{0}' <= `date`".format(st_date))

            if ed_date is not None:
                if 0 < len(extend_sql):
                    extend_sql.append("AND")

                extend_sql.append("`date` <= '{0}'".format(ed_date))

            if 0 < len(extend_sql):
                sql = sql + " WHERE " + " ".join(extend_sql)

            sql = sql + ";"

            cursor.execute(sql)
            rs = cursor.fetchall()

            ret = []
            for row in rs:
                ret.append((row["spc_date"], row["mk_open"], row["mk_close"]))

            return ret

    def select_unfilled_trd_stock(self, weights_table: str) -> dict:
        with self.connection.cursor() as cursor:
            sql = "SELECT " \
                  "`date`, `shtcode`, `target_weight`, `current_weight` " \
                  "FROM {0} " \
                  "WHERE `date` = (SELECT `date` FROM {0} WHERE `rebal_decision` = 1 " \
                  "ORDER BY `date` DESC limit 1)" \
                  "AND `exec_success` = 0;".format(weights_table)

            cursor.execute(sql)
            rs = cursor.fetchall()

            ret = []
            for row in rs:
                ret.append((row['date'], row['shtcode'], row['target_weight'], row['current_weight']))
            return ret

    def select_shtname(self, shtcode: str) -> dict:
        with self.connection.cursor() as cursor:
            sql = "SELECT " \
                  "`name` " \
                  "FROM code_master " \
                  "WHERE `shtcode` = '{0}';".format(shtcode)

            cursor.execute(sql)
            ret = cursor.fetchone()

            return ret

    def get_market_delay_sec(self, date: str, normal_st_time: str, normal_ed_time:str) -> dict:
        with self.connection.cursor() as cursor:
            sql = "SELECT " \
                  "COUNT(*) AS cnt, IFNULL(TIME_TO_SEC(TIMEDIFF(mk_open,'{0}')), 0) AS st_delay_sec, " \
                  "IFNULL(TIME_TO_SEC(TIMEDIFF(mk_close,'{1}')), 0) AS ed_delay_sec, IFNULL(comment, '') AS cmt " \
                  "FROM spc_trd_time WHERE `date` = '{2}';".format(normal_st_time, normal_ed_time, date)

            cursor.execute(sql)
            rs = cursor.fetchone()
            ret = {
                "cnt": rs["cnt"],
                "st_delay_sec": int(rs["st_delay_sec"]),
                "ed_delay_sec": int(rs["ed_delay_sec"]),
                "comment": rs["cmt"],
            }

            return ret

    def get_data_rcv_result(self) -> dict:
        with self.connection.cursor() as cursor:
            ret = {}
            cur_date = datetime.date.today()

            sql = "SELECT COUNT(*) AS cnt FROM code_master " \
                  "WHERE last_update = '{0}';".format(cur_date)
            cursor.execute(sql)
            rs = cursor.fetchone()
            ret["master_cnt"] = rs["cnt"]

            sql = "SELECT COUNT(DISTINCT shtcode) AS cnt FROM kiwoom_day_candle " \
                  "WHERE `date` = (SELECT MAX(`date`) FROM kiwoom_day_candle);"
            cursor.execute(sql)
            rs = cursor.fetchone()
            ret["daily_chart_cnt"] = rs["cnt"]

            sql = "SELECT COUNT(DISTINCT shtcode) AS cnt FROM kiwoom_trd_trends " \
                  "WHERE `date` = (SELECT MAX(`date`) FROM kiwoom_trd_trends);"
            cursor.execute(sql)
            rs = cursor.fetchone()
            ret["daily_trend_cnt"] = rs["cnt"]

            sql = "SELECT " \
                  "cm.shtcode AS shtcode, cm.`name` AS item_name " \
                  "FROM code_master cm " \
                  "LEFT JOIN kiwoom_day_candle kdc " \
                  "ON cm.shtcode = kdc.shtcode AND kdc.`date` = (SELECT MAX(`date`) FROM kiwoom_day_candle) " \
                  "WHERE kdc.id IS NULL AND cm.last_update = '{0}';".format(cur_date)

            cursor.execute(sql)
            rs = cursor.fetchall()
            ret["daily_chart_ext"] = rs

            sql = "SELECT " \
                  "cm.shtcode AS shtcode, cm.`name` AS item_name " \
                  "FROM code_master cm " \
                  "LEFT JOIN kiwoom_trd_trends ktt " \
                  "ON cm.shtcode = ktt.shtcode AND ktt.`date` = (SELECT MAX(`date`) FROM kiwoom_trd_trends) " \
                  "WHERE ktt.id IS NULL AND cm.last_update = '{0}';".format(cur_date)

            cursor.execute(sql)
            rs = cursor.fetchall()
            ret["daily_trend_ext"] = rs

            sql = "SELECT `shtcode`, `name` AS item_name FROM `code_master` WHERE " \
                  "`listing_date` = '{0}';".format(cur_date)
            cursor.execute(sql)
            rs = cursor.fetchall()
            ret["new_listing"] = rs

            return ret

    def get_invest_universe(self):
        with self.connection.cursor() as cursor:
            ret = []
            cur_date = datetime.date.today()

            sql = "SELECT `shtcode` " \
                  "FROM `invest_universe` " \
                  "WHERE `universe_date` < '{0}' AND `finish_date` >= '{0}';".format(cur_date)

            cursor.execute(sql)
            rs = cursor.fetchall()

            for row in rs:
                ret.append(row["shtcode"])

            return ret

    def get_db_connection(self):
        return self.connection

    def get_subscriber_info(self, user_id: str):
        with self.connection.cursor() as cursor:
            sql = "SELECT * FROM subscriber WHERE id = %s"
            cursor.execute(sql, (user_id))
            rows = cursor.fetchall()
        return rows

    def get_balance(self, account: str, date):
        with self.connection.cursor() as cursor:
            sql = "SELECT * FROM balance WHERE account = %s AND date >= %s"
            cursor.execute(sql, (account, date))
            rows = cursor.fetchall()
        return rows

    def get_account_stock(self, account: str, date):
        with self.connection.cursor() as cursor:
            sql = "SELECT * FROM balance_stock WHERE account = %s AND date = %s"
            cursor.execute(sql, (account, date))
            rows = cursor.fetchall()
        return rows

    def get_all_trade(self, account: str, date):
        with self.connection.cursor() as cursor:
            sql = "SELECT * FROM trade WHERE account = %s AND date >= %s ORDER BY date ASC"
            cursor.execute(sql, (account, date))
            rows = cursor.fetchall()
        return rows

    def get_all_universe(self):
        with self.connection.cursor() as cursor:
            sql = "SELECT * FROM universe"
            cursor.execute(sql, ())
            rows = cursor.fetchall()
        return rows


if __name__ == "__main__":
    config_file_path = "C:\\config\\config.ini"
    with Database(config_file_path) as dg:
        dg.show_tables()
