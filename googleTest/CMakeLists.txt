cmake_minimum_required (VERSION 2.8)

project(gtest_demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall")

find_package(GTest REQUIRED)

find_library(GMOCK
        NAMES gmock
        PATH /usr/local/lib /usr/lib)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(MyTests test_main.cpp test.cpp)
target_link_libraries(MyTests ${GMOCK} ${GTEST_BOTH_LIBRARIES} pthread)
add_test(Test MyTests)
enable_testing()
