#pragma once

#include "figure.hpp"

template <typename T>
class Square : public Figure<T> {
public:
    std::vector< std::pair<T, T> > points;

    Square() {
        points.resize(4, {0, 0});
    }

    Square(const std::vector< std::pair<T, T> > &v) : points(v) {
        if (v.size() != 4) {
            throw std::logic_error("Octagon must have 4 points");
        }
    }

    T square() const {
        T length = points[1].second - points[0].second;
        T width = length;
        T square = width * length;
        return square;
    }

    typename Figure<T>::point center() const {
        T x = (points[2].first - points[1].first) / 2;
        T y = (points[1].second - points[0].second) / 2;
        return {x, y};
    }

    Square& operator=(const Square<T> &&other) {
        this->points = std::move(other.points);
        return *this;
    }

    Square& operator=(Square<T> &other) {
        this->points = other.points;
        return *this;
    }

    bool operator==(const Square &other) const {
        for (size_t i = 0; i < 4; ++i) {
            if (this->points[i] != other.points[i]) {
                return 0;
            }
        }

        return 1;
    }

    operator double() const override;

    ~Square() = default;
};

template <typename T>
std::istream &operator>>(std::istream &is, Square<T> &s) {
    for (size_t i = 0; i < 4; ++i) {
        is >> s.points[i].first >> s.points[i].second;
    }
    return is;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Square<T> &s) {
    for (size_t i = 0; i < 4; ++i) {
        os << "(" << s.points[i].first << ";" << s.points[i].second << ")"; 
    }
    return os;
}

template <typename T>
inline Square<T>::operator double() const {
    return static_cast<double>(this->square());
}