cmake_minimum_required(VERSION 3.18)

set(LIBRARY_OUTPUT_NAME chem)

add_library(${LIBRARY_OUTPUT_NAME} INTERFACE)

target_include_directories(${LIBRARY_OUTPUT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(${LIBRARY_OUTPUT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR}/../../src)
