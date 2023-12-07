#pragma once

#include <iostream>
#include <cmath>

class Point {
public:            
    Point();
    Point(double x, double y);
    Point(std::istream &is);

    double getX() const;
    double getY() const;
    double distance(Point &other);

    friend std::istream &operator>>(std::istream &is, Point &p);
    friend std::ostream &operator<<(std::ostream &os, const Point &p);
private:
    double x_, y_;
};

Point operator+(const Point &p1, const Point &p2);
Point operator-(const Point &p);
Point operator-(const Point &p1, const Point &p2);
Point operator*(const Point &p, const double x);
Point operator*(const double x, const Point &p);