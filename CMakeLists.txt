cmake_minimum_required(VERSION 3.12)
project(PdfMerge)

find_package(pybind11 REQUIRED)

pybind11_add_module(pdf_merge MODULE pdf_merge.cpp)

target_link_libraries(pdf_merge PRIVATE PoDoFo)
