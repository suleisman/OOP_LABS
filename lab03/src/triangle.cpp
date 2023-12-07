#include "triangle.hpp"
#include <vector>

Triangle::Triangle(std::istream &is) {
    for (size_t i = 0; i < 3; ++i) {
        is >> points[i];
    }
}

Triangle::Triangle(Point &&p1, Point &&p2, Point &&p3) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
}

void Triangle::print(std::ostream &os) const {
    for (const auto &p : points) {
        os << p << " ";
    }
    os << std::endl;
}

double Triangle::square() const {
    double square = 0.0;

    double x1 = (points[2].getX() - points[0].getX()) * (points[2].getX() - points[0].getX());
    double y1 = (points[2].getY() - points[0].getY()) * (points[2].getY() - points[0].getY());
    double a = std::sqrt(x1 + y1);

    return pow(a, 2) * std::sqrt(3) / 4;
}

Point Triangle::center() const {
    Point center = points[0] + points[1] + points[2];
    return Point(center.getX() / 3, center.getY() / 3);
}

Figure& Triangle::move(Figure &&other) noexcept {
    const Triangle *otherSquare = dynamic_cast<const Triangle*>(&other);
    for (size_t i = 0; i < 3; ++i) {
        points[i] = std::move(otherSquare->points[i]);
    }
    return *this;
}

Figure& Triangle::operator=(const Figure &other) {
    const Triangle *otherSquare = dynamic_cast<const Triangle*>(&other);
    for (size_t i = 0; i < 3; ++i) {
        points[i] = otherSquare->points[i];
    }
    return *this;
}

bool Triangle::operator==(const Figure &other) const {
    const Triangle *otherSquare = dynamic_cast<const Triangle*>(&other);
    for (size_t i = 0; i < 3; ++i) {
        if (points[i].getX() != otherSquare->points[i].getX() || points[i].getY() != otherSquare->points[i].getY()) {
            return 0;
        }
    }
    return 1;
}