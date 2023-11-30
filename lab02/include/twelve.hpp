#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>


class Twelve {
    public:

        Twelve();
        Twelve(const size_t &n, unsigned char t = 0);
        Twelve(const std::initializer_list<unsigned char> &t);
        Twelve(const std::string t);
 
        Twelve(const Twelve& other);
        Twelve(Twelve&& other) noexcept;
        virtual ~Twelve() noexcept;

        std::ostream &print(std::ostream &os);

        Twelve operator+ (const Twelve &other) const;
        Twelve operator- (const Twelve &other) const;
        Twelve operator= (const Twelve &other);
        bool operator< (const Twelve &other) const;
        bool operator> (const Twelve &other) const;
        bool operator<= (const Twelve &other) const;
        bool operator>= (const Twelve &other) const;
        bool operator != (const Twelve &other) const;
        bool operator== (const Twelve &other) const;

    private:
        size_t size;
        unsigned char *number;
        


};
bool isTwelveDigit(const char &c);