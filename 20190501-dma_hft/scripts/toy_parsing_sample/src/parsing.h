// parsing.h
#pragma once

#include <Python.h>

PyObject* char_to_pylong(char* str, int len);
PyObject* char_to_pyfloat(char* str, int tot_len, int int_part_len);

PyObject* parse_k200_fut_comp_block(char* raw_data);
PyObject* parse_k200_fut_exec(char* raw_data);
PyObject* parse_k200_fut_limit_ord(char* raw_data);
PyObject* parse_k200_fut_exec_limit_ord(char* raw_data);
PyObject* parse_k200_fut_close_product(char* raw_data);

PyObject* parse_k200_fut_prd_info_data(char* raw_data);