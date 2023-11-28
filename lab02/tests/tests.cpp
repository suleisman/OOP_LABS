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


