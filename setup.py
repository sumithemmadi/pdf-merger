import os
import pybind11

from setuptools import setup, Extension

ext_modules = [
    Extension(
        'pdf_merge',
        ['./cpp_pdf_merger/pdf_merge.cpp'],
        libraries=['podofo'],
        include_dirs=[pybind11.get_include()],
    ),
]

setup(
    name='pdf_merge',
    version='1.0',
    description='PDF Merge Python Extension',
    ext_modules=ext_modules,
)
