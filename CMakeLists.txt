#root folder
cmake_minimum_required(VERSION 3.10)
project(tcpsf C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

add_subdirectory(src)

add_subdirectory(tests)

