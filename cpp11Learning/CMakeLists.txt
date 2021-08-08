cmake_minimum_required(VERSION 3.6)

project(cpp11Learning)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fno-elide-constructors")

add_subdirectory(ch02)
add_subdirectory(ch03)
add_subdirectory(ch04)
add_subdirectory(ch05)
add_subdirectory(ch06)
add_subdirectory(ch07)
add_subdirectory(ch08)
