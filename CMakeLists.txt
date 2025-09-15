cmake_minimum_required(VERSION 3.10)
project(tcpsf C)
set(cmake_c_STANDARD 99)

include_directories(include)

add_subdirectory(src)

add_subdirectory(tests)

