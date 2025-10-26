cmake_minimum_required(VERSION 3.10)
project(CryptoTool)

set(CMAKE_CXX_STANDARD 11)

# 包含头文件目录
include_directories(include)

# 添加可执行文件 - 使用正确的文件路径
add_executable(CryptoTool
    crypt/main.cpp
    crypt/filehandler.cpp
    crypt/menu.cpp
    crypt/crypto.cpp
    )