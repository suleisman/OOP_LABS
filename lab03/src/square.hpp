#pragma once

#include "figure.hpp"
#include "point.hpp"

class Square : public Figure {
public:
    Square();
    Square(Point &&p1, Point &&p2, Point &&p3, Point &&p4);
    Square(std::istream &is);

    void print(std::ostream &os) const;
    double square() const;
    Point center() const;

    Figure& move(Figure &&other) noexcept;
    Figure& operator=(const Figure &other);
    bool operator==(const Figure &other) const;

    virtual ~Square() = default;
private:
    Point points[4];
};