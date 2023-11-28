#include <gtest/gtest.h>
#include "twelve.hpp"



TEST(test01, twelve) {
    Twelve num1("A8");
    Twelve num2(num1);
    ASSERT_TRUE(num1 == num2);
}

TEST(test02, twelve) {
    Twelve num1({'1', 'A', 'B'});
    Twelve num2 = num1;
    ASSERT_TRUE(num1 == num2);
}

TEST(test03, twelve) {
    Twelve num1("5A");
    Twelve num2({'1', '6'});
    ASSERT_TRUE((num1 + num2) == Twelve("74"));
}

TEST(test04, twelve) {
    Twelve num1(2,'B');
    Twelve num2({'1'});
    ASSERT_TRUE((num1 - num2) == Twelve("BA"));
}

TEST(test05, twelve) {
    Twelve num1("8B");
    Twelve num2({'1'});
    ASSERT_TRUE(num1 != num2);
}

TEST(test06, twelve) {
    Twelve num1(3,'B');
    Twelve num2("AA1");
    ASSERT_TRUE(num1 > num2);
}

TEST(test07, twelve) {
    Twelve num1({'1', '1'});
    Twelve num2({'A', '2'});
    ASSERT_TRUE(num1 < num2);
}


TEST(test08, twelve) {
    Twelve num1({'B','8', 'A'});
    Twelve num2("B8A");
    ASSERT_TRUE(num1 <= num2);
}

TEST(test09, twelve) {
    Twelve num1({'1','B','4'});
    Twelve num2({'1'});
    ASSERT_FALSE(num2 >= num1);
}

TEST(test10, twelve) {
    Twelve num1({'1'});
    Twelve num2({'1'});
    ASSERT_TRUE((num1 + num2) == Twelve({'2'}));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


/*
cmake_minimum_required(VERSION 3.10)
project(lab02)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task main.cpp src/twelve.cpp include/twelve.hpp)
add_executable(tests src/twelve.cpp include/twelve.hpp tests/tests.cpp)

target_link_libraries(tests  PRIVATE GTest::GTest)

target_include_directories(task PRIVATE include)
target_include_directories(tests PRIVATE include)

*/