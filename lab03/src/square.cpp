#include "square.hpp"

Square::Square(std::istream &is) {
    for (size_t i = 0; i < 4; ++i) {
        is >> points[i];
    }
}

Square::Square(Point &&p1, Point &&p2, Point &&p3, Point &&p4) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
}

void Square::print(std::ostream &os) const{
    for (const auto &p : points) {
        os << p << " ";
    }
    os << std::endl;
}

double Square::square() const {
    double square = 0.0;

    double xLength = (points[1].getX() - points[0].getX()) * (points[1].getX() - points[0].getX());
    double yLength = (points[1].getY() - points[0].getY()) * (points[1].getY() - points[0].getY());
    double length = std::sqrt(xLength + yLength);

    square = length * length;
    return floor(square * 100) / 100; 
}

Point Square::center() const {
    double x = 0.0;
    double y = 0.0;

    x = (((points[3].getX() - points[0].getX()) / 2) * 100) / 100;
    y = (((points[1].getY() - points[0].getY()) / 2) * 100) / 100;

    return Point(x, y);
}

Figure& Square::move(Figure &&other) noexcept {
    const Square *otherSquare = dynamic_cast<const Square*>(&other);
    for (size_t i = 0; i < 4; ++i) {
        points[i] = std::move(otherSquare->points[i]);
    }
    return *this;
}

Figure& Square::operator=(const Figure &other) {
    const Square *otherSquare = dynamic_cast<const Square*>(&other);
    for (size_t i = 0; i < 4; ++i) {
        points[i] = otherSquare->points[i];
    }
    return *this;
}

bool Square::operator==(const Figure &other) const {
    const Square *otherSquare = dynamic_cast<const Square*>(&other);
    for (size_t i = 0; i < 4; ++i) {
        if (points[i].getX() != otherSquare->points[i].getX() || points[i].getY() != otherSquare->points[i].getY()) {
            return 0;
        }
    }
    return 1;
}