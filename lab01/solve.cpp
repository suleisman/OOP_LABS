#include "solve.hpp"

int number_vowels(std::string & s) {
    int num = 0;
    for (char a : s) {
        bool is_vowel = false;
        for (char b : vowels) {
            if (a == b) {
                ++ num;
                break;
            }
        }
    }

    return num;
}