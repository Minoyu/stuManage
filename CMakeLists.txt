cmake_minimum_required(VERSION 3.8)
project(stuManage)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES source/main.cpp source/menu.cpp header/main.h source/function.cpp source/student.cpp)
add_executable(stuManage ${SOURCE_FILES})