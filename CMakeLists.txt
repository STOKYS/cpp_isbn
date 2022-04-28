cmake_minimum_required(VERSION 3.21)
project(cpp_isbn)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_isbn main.cpp Kniha.cpp Kniha.hpp)
