#include <gtest/gtest.h>
#include "solve.hpp"

TEST(test01, vowels) {
    std::string s = "this this this this";
    ASSERT_TRUE(number_vowels(s) == 4);
}

TEST(test02, vowels) {
    std::string s = "aeiou";
    ASSERT_TRUE(number_vowels(s) == 5);
}

TEST(test03, vowels) {
    std::string s = "bcdBCD";
    ASSERT_TRUE(number_vowels(s) == 0);
}

TEST(test04, vowels) {
    std::string s = "a b# c! d e? k l m";
    ASSERT_TRUE(number_vowels(s) == 2);
}

TEST(test05, vowels) {
    std::string s = " ";
    ASSERT_TRUE(number_vowels(s)  );
}

TEST(test06, vowels) {
    std::string s = "        ";
    ASSERT_TRUE(number_vowels(s) == 0);
}

TEST(test07, vowels) {
    std::string s = "vowels";
    ASSERT_TRUE(number_vowels(s) == 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}