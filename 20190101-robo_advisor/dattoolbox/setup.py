# -*- coding: utf-8 -*-

import importlib.util
import os
from importlib.machinery import SourceFileLoader

from setuptools import setup, find_packages

version_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "VERSION")
version_loader = SourceFileLoader("version", version_path)
version_spec = importlib.util.spec_from_loader(version_loader.name, version_loader)
version = importlib.util.module_from_spec(version_spec)
version_loader.exec_module(version)

package_dir = {'': 'src'}

setup(
    name='dattoolbox',
    packages=find_packages('src'),
    package_dir=package_dir,
    include_package_data=True,
    version=version.VERSION,
    author='Youngmin Bae',
    author_email='',
    zip_safe=False,
)
