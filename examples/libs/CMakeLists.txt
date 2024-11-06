cmake_minimum_required(VERSION 3.18)

set(LIBRARY_OUTPUT_NAME chem.so)

set(SRCS chem.cpp)

add_library(${LIBRARY_OUTPUT_NAME} ${SRCS})

target_include_directories(${LIBRARY_OUTPUT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(${LIBRARY_OUTPUT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../../src)
