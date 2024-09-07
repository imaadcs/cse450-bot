cmake_minimum_required(VERSION 3.10)

project(cse450bot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(cse450bot src/main.cpp)

include_directories(/usr/include)

target_link_libraries(cse450bot dpp)
