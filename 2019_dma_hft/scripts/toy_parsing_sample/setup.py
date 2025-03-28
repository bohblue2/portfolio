# -*- coding: utf-8 -*-
import os

from setuptools import setup, Extension

packages = [
	"dat_hft",
]

ext_modules = [
	Extension(
		name="dat_hft._parsing",
		sources=[
			os.path.join("src", "parsing.c"),
			os.path.join("src", "parsing_wrap.c"),
		],
	),
]

classifiers = [
	"Programming Language :: Python :: 3 :: Only",
]

setup(
	name="dat_hft",
	version="0.0.1",
	description="DAT HFT",
	author="DAT",
	python_requires=">=3",
	ext_modules=ext_modules,
	packages=packages,
	package_dir={"dat_hft": "src"},
	classifiers=classifiers,
)
