#include <iostream>

#include "twelve.hpp"

Twelve::Twelve(): size{0}, number{nullptr}{}

bool isTwelveDigit(const char &c) {
    return (('0' <= c && c <= '9') || (c == 'A') || (c == 'B'));
}
Twelve::Twelve(const size_t &n, unsigned char t) {
    
    number = new unsigned char[n];
    for (size_t i = 0; i < n; i++)
        number[i] = t;
    size = n;
}

Twelve::Twelve(const std::initializer_list<unsigned char> &t) {
    
    number = new unsigned char[t.size()];
    size = t.size();

    size_t i{size};
    for (unsigned char c : t) {
        if (!isTwelveDigit(c)) {
            throw std::logic_error("Twelve digit can't be negative and must be undenary digit");
        }
        number[--i] = c;
    }
}


Twelve::Twelve(const std::string t) {
    size = t.size();
    number = new unsigned char[size];
    for (size_t i = size - 1, j = 0; j < size; i--, j++) {
        if (!isTwelveDigit(t[i])) {
            throw std::logic_error("Twelve digit can't be negative and must be undenary digit");
        }

        number[i] = t[j];
    }
}

Twelve::Twelve(const Twelve &other) {

    size = other.size;
    number = new unsigned char[size];
    for (size_t i = 0; i < size; i++) {
        number[i] = other.number[i];
    }
}

Twelve::Twelve(Twelve &&other) noexcept {
    
    size = other.size;
    number = other.number;  

    other.size = 0;
    other.number = nullptr;
}


Twelve Twelve::operator=(const Twelve &other)
{
    if (&other !=this) {
        delete[] number;
        size = other.size;
        number = new unsigned char[size];
        for (size_t i = 0; i < size; i++) {
            number[i] = other.number[i];
        }
    }
    return *this;
}

Twelve Twelve::operator-(const Twelve &other) const {
    size_t resultSize = std::max(other.size, size)+1;
    std::string result (resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1, d2;
        if(i < size) {
            if(number[i] != 'A' && number[i] != 'B') {
                d1 = number[i] - '0';
            } else{
                if(number[i] == 'A') {
                    d1 = 10;

            }
                if(number[i] == 'B') {
                    d1 = 11;
                }}
        } else {
            d1 = 0;
        }

        if(i < other.size) {
            if(other.number[i] != 'A' && other.number[i] != 'B') {
                d2 = other.number[i] - '0';
            } else{
                if(other.number[i] == 'A') {
                    d2 = 10;

            }
                if(other.number[i] == 'B') {
                    d2 = 11;
                }}
        } else {
            d2 = 0;
        }
        int diff = d1 - d2 - carry;
        if(diff < 0) {
            diff += 12;
            carry = 1;

        } else {
            carry = 0;
        }
        if(diff != 10 && diff != 11) {
            result[i] = diff + '0';
        } else {
            if(diff == 10) {
                result[i] = 'A';
            }
            if(diff == 11) {
                result[i] = 'B';
            } 
        }
        
    }
    if(result[resultSize-1] == '0') {
        result.erase(resultSize-1,1);
    }
    std::reverse(result.begin(), result.end());
    return  Twelve(result);
}


 
Twelve Twelve::operator+(const Twelve &other) const {
    size_t resultSize = std::max(other.size, size)+1;
    std::string result (resultSize, '0');
    int carry = 0;
    for (size_t i = 0; i < resultSize; i++) {
        int d1, d2;
        if(i < size) {
            if(number[i] != 'A' && number[i] != 'B') {
                d1 = number[i] - '0';
            } else{
                if(number[i] == 'A') {
                    d1 = 10;

            }
                if(number[i] == 'B') {
                    d1 = 11;
                }}
        } else {
            d1 = 0;
        }

        if(i < other.size) {
            if(other.number[i] != 'A' || other.number[i] != 'B') {
                d2 = other.number[i] - '0';
            } else {
                if(other.number[i] == 'A') {
                    d2 = 10;

            }
                if(other.number[i] == 'B') {
                    d2 = 11;
                }}
        } else {
            d2 = 0;
        }
        int sum = d1 + d2 + carry;
        if(sum % 12 != 11 && sum % 12 != 10) {
            result[i] = sum % 12 +'0';
        } else {
            if(sum % 12 == 11) {
                result[i] = 'B';
            }
            if(sum % 12 == 10) {
                result[i] = 'A';
            }}
        carry = sum / 12;
    }

    if(carry > 0) {
        if(carry  != 10 && carry != 11) {
            result[resultSize -1 ] = carry +'0';
          
            
        } else{
        if(carry == 11) {
            result[resultSize - 1] = 'B';
        }
        if(carry == 10)
        {   result[resultSize - 1] = 'A';}
    }
    }
    if(result[resultSize-1] == '0') {
        result.erase(resultSize - 1, 1);
    }

    std::reverse(result.begin(),result.end());
    return Twelve(result);

    
}

bool Twelve::operator==(const Twelve &other) const {
    if (&other == this) {
        return true;
    }
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; i++) {
        if (number[i] != other.number[i]) {
            return false;
        }
    }
    return true;
}

bool Twelve::operator!=(const Twelve &other) const {
    if (*this == other) {
        return false;
    }
    return true;
}

bool Twelve::operator<(const Twelve &other) const {
    if (&other == this) {
        return false;
    }

    if (size < other.size) {
        return true;
    }
    else if (size > other.size) {
        return false;
    }
    else {
        for (size_t i = size; i--;) {
            if (number[i] < other.number[i]) {
                return true;
            }
            else if (number[i] > other.number[i]){
                return false;
            }
            else { 
            continue; }
        }
        return false;
    }
}

bool Twelve::operator<=(const Twelve &other) const {
    if (*this > other) {
        return false;
    }
    return true;
}

bool Twelve::operator>(const Twelve &other) const {
    if (*this < other || *this == other) {
        return false;
    }
    return true;
}

bool Twelve::operator>=(const Twelve &other) const {
    if (*this < other) {
        return false;
    }
    return true;
}

std::ostream &Twelve::print(std::ostream &os) {
    for (size_t i = size; i--;) {
        os << number[i];
    }
    os << std::endl;
    return os;
}

Twelve::~Twelve() noexcept {
    if (size > 0) {
        size = 0;
        delete[] number;
        number = nullptr;
    }
}