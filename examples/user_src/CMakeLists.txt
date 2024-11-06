cmake_minimum_required(VERSION 3.18)

set(SRCS test.cpp)

add_executable(test ${SRCS})

target_include_directories(test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../libs)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../libs/Operations)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../libs/Quantities)
target_link_directories(test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../libs/)
target_link_libraries(test chem.so)
