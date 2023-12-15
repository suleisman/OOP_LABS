#include "point.hpp"

Point::Point() : x_(0.0), y_(0.0) {}

Point::Point(double x, double y) : x_(x), y_(y) {}

double Point::getX() const {
    return x_;
}

double Point::getY() const {
    return y_;
}

double Point::distance(Point &other) {
    return std::sqrt((other.x_ - x_) * (other.x_ - x_) + (other.y_ - y_) * (other.y_ - y_));
}

Point operator+(const Point &p1, const Point &p2) {
    return Point{p1.getX() + p2.getX(), p1.getY() + p2.getY()};
}

Point operator-(const Point &p) {
    return Point{-p.getX(), -p.getY()};
}

Point operator-(const Point &p1, const Point &p2) {
    return p1 + (-p2);
}

Point operator*(const Point &p, const double x) {
    return Point{p.getX() * x, p.getY() * x};
}

Point operator*(const double x, const Point &p) {
    return p * x;
}

std::istream &operator>>(std::istream &is, Point &p) {
    is >> p.x_ >> p.y_;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << "(" << p.x_ << ";" << p.y_ << ")";
    return os;
}