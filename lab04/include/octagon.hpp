#pragma once

#include "figure.hpp"

template <typename T>
class Octagon : public Figure<T> {
    public:
    std::vector<std::pair<T, T>> points;

    Octagon(){
        points.resize(8, {0,0});
    }

    Octagon(const std::vector<std::pair<T, T>>& v) :  points(v) {
         if (v.size() != 8) {
            throw std::logic_error("Octagon must have 8 points");
        }
    }

    T square() const override {
        T area = 0;
        for (int i = 0; i < 7; ++i) {
            area += points[i].first * points[i + 1].second - points[i + 1].first * points[i].second;
        }
        area += points[7].first * points[0].second - points[0].first * points[7].second;
        return std::abs(area) / 2;
    }

    typename Figure<T>::point center() const override {
        T centerX = 0, centerY = 0;
        for (const auto &point : points) {
            centerX += point.first;
            centerY += point.second;
        }
        centerX /= 8;
        centerY /= 8;
        return {centerX, centerY};
    }

    Octagon& operator=(const Octagon<T>& other) {
        points = other.points;
        return *this;
    }

    Octagon& operator=(Octagon<T>&& other) {
        points = std::move(other.points);
        return *this;
    }

    bool operator==(const Octagon& other) const {
        if (points.size() != other.points.size()) {
            return false;
        }
        for (size_t i = 0; i < points.size(); i++) {
            if (points[i] != other.points[i]) {
                return false;
            }
        }
        return true;
    }
    
    operator double() const override;

    ~Octagon() = default;

}; 

template <typename T>
std::ostream& operator<<(std::ostream& os, const Octagon<T>& pent) {
    for (size_t i = 0; i != 8; ++i) {
        os << "(" << pent.points[i].first << ", " << pent.points[i].second << ")";
    }
    return os;
}

template <typename T>
 std::istream& operator>>(std::istream& is, Octagon<T>& fig) {
    for (size_t i = 0; i != 8; ++i) {
        is >> fig.points[i].first >> fig.points[i].second;
    }

    return is;
}

template <typename T>
inline Octagon<T>::operator double() const {
    return static_cast<double>(this->square());
}