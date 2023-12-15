#pragma once

#include "figure.hpp"

template <typename T>
class Triangle : public Figure<T> {
public:
    std::vector< std::pair<T, T> > points;

    Triangle() {
        points.resize(3, {0, 0});
    }

    Triangle(const std::vector< std::pair<T, T> > &v) : points(v) {
        if (v.size() != 3) {
            throw std::logic_error("Triangle must have 3 points");
        }
    }

    T square() const {
        typename Figure<T>::point baseCenterCoords = {points[2].first + points[0].first / 2,
            points[2].second + points[0].second / 2};
        typename Figure<T>::point highCoords = {baseCenterCoords.first, points[1].second};
        T highLength = highCoords.second - baseCenterCoords.second;
        T baseLength = points[2].first - points[0].first; 
        return highLength * baseLength * 0.5;
    }

    typename Figure<T>::point center() const {
        typename Figure<T>::point center = {points[0].first + points[1].first + points[2].first,
            points[0].second + points[1].second + points[2].second};
        return {center.first / 3, center.second / 3};
    }

    Triangle& operator=(const Triangle<T> &&other) {
        this->points = std::move(other.points);
        return *this;
    }

    Triangle& operator=(Triangle<T> &other) {
        this->points = other.points;
        return *this;
    }

    bool operator==(const Triangle &other) const {
        for (size_t i = 0; i < 3; ++i) {
            if (this->points[i] != other.points[i]) {
                return 0;
            }
        }

        return 1;
    }

    operator double() const override;

    ~Triangle() = default;
};

template <typename T>
std::istream &operator>>(std::istream &is, Triangle<T> &t) {
    for (size_t i = 0; i < 4; ++i) {
        is >> t.points[i].first >> t.points[i].second;
    }
    return is;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Triangle<T> &t) {
    for (size_t i = 0; i < 3; ++i) {
        os << "(" << t.points[i].first << ";" << t.points[i].second << ")"; 
    }
    return os;
}

template <typename T>
inline Triangle<T>::operator double() const {
    return static_cast<double>(this->square());
}