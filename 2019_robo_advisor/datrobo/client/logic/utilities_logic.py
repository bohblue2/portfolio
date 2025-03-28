import sqlalchemy
import pandas as pd
import numpy as np
import datetime
from pandas.io import sql

class Utilities(object):
    def __init__(self):
        pass

    def set_db_engine(self, DB_ID, DB_PWD, DB_IP, DB_PORT, DB_NAME):
        """
        :param DB_ID: user id for db
        :param DB_PWD: user password for db and id
        :param DB_IP: address
        :param DB_PORT: port
        :param DB_NAME: specific db name
        :return: DB engine to use sql query
        """
        conn_str = "mysql+pymysql://{0}:{1}@{2}:{3}/{4}?charset={5}". \
            format(DB_ID, DB_PWD, DB_IP, DB_PORT, DB_NAME, 'utf8')
        engine = sqlalchemy.create_engine(conn_str)
        return engine

    def sql_pop(self, engine, table, condition, index_col = None):

        read_query = """
        SELECT * FROM `{0}` WHERE {1};        
        """.format(table.lower(), condition)

        if index_col is not None :
            ret = pd.read_sql_query(sql=read_query, con = engine, index_col=index_col)
        else :
            ret = pd.read_sql_query(sql=read_query, con=engine)

        del_query = """
        DELETE FROM `{0}` WHERE {1};
        """.format(table.lower(), condition)
        sql.execute(sql = del_query, con=engine)

        return ret

    def sql_read(self, engine, table, condition, index_col = None):

        read_query = """
        SELECT * FROM `{0}` WHERE {1};        
        """.format(table.lower(), condition)

        if index_col is not None :
            ret = pd.read_sql_query(sql=read_query, con = engine, index_col=index_col)
        else :
            ret = pd.read_sql_query(sql=read_query, con=engine)

        return ret

    def sql_read_column(self, engine, table, condition, column,index_col = None):

        read_query = """
        SELECT `{0}` FROM `{1}` WHERE {2};        
        """.format(column, table.lower(), condition)

        if index_col is not None :
            ret = pd.read_sql_query(sql=read_query, con = engine, index_col=index_col)
        else :
            ret = pd.read_sql_query(sql=read_query, con=engine)

        return ret


    def sql_update_double(self, engine, table, condition, index_col, double_value):
        update_query = """UPDATE `{0}` SET `{1}` = {2:.8f} WHERE  {3} ;""".format(table.lower(), index_col, double_value, condition)

        sql.execute(sql=update_query, con=engine)

    def sql_execute(self, engine, query):
        sql.execute(sql=query, con=engine)

    def sql_push(self, df, engine, table, index_col=None):
        if index_col is not None :
            df.to_sql(name = table.lower(), con=engine, if_exists='append', index = True, index_label=index_col)
        else :
            df.to_sql(name = table.lower(), con=engine, if_exists='append', index = False)


    def int2datetime(self, intmstime):
        ret = datetime.datetime.fromtimestamp(intmstime/1000)
        return ret

    def datetime2str(self, dt):
        return dt.strftime("%Y-%m-%d %H:%M:%S")
