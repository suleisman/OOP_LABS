cmake_minimum_required(VERSION 3.10)
project(lab02)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task main.cpp src/twelve.cpp include/twelve.hpp)
add_executable(tests src/twelve.cpp include/twelve.hpp tests/tests.cpp)

target_link_libraries(tests  PRIVATE GTest::GTest)

target_include_directories(task PRIVATE include)
target_include_directories(tests PRIVATE include)
