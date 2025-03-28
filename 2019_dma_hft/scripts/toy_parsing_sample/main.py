# -*- coding: utf-8 -*-
import dat_hft.parsing

with open("sise2local.ALL_FO.0408", "rb") as f:
	while True:
		line = f.readline()

		if not line:
			break

		data = line[17:]
		data_kind = data[:5]

		# K200선물_경쟁+협의합산
		if b"C4014" == data_kind:
			print(dat_hft.parsing.parse_k200_fut_comp_block(data))
			pass
		# K200선물_체결 (K200_FUT_EXEC)
		elif b"A3014" == data_kind:
			print(dat_hft.parsing.parse_k200_fut_exec(data))
			pass
		# K200선물_우선호가 (K200_FUT_LIMIT_ORD)
		elif b"B6014" == data_kind:
			print(dat_hft.parsing.parse_k200_fut_limit_ord(data))
			pass
		# K200선물_체결_우선호가 (K200_FUT_EXEC_LIMIT_ORD)
		elif b"G7014" == data_kind:
			print(dat_hft.parsing.parse_k200_fut_exec_limit_ord(data))
			pass
		# K200선물_종목마감 (K200_FUT_CLOSE_PRODUCT)
		elif b"A6014" == data_kind:
			print(dat_hft.parsing.parse_k200_fut_close_product(data))
			pass
		# K200선물_종목정보 데이터 (K200_FUT_PRD_INFO_DATA)
		elif b"A0014" == data_kind:
			print(dat_hft.parsing.parse_k200_fut_prd_info_data(data))
			pass
