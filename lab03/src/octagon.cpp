#include "octagon.hpp"

Octagon::Octagon(std::istream &is) {
    for (size_t i = 0; i < 8; ++i) {
        is >> points[i];
    }
}

void Octagon::print(std::ostream &os) const{
    for (const auto &p : points) {
        os << p << " ";
    }
    os << std::endl;
}

double Octagon::square() const {
    double result = 0;
    for(unsigned i = 0; i < 8; ++i) {
        Point p1 = i ? points[i - 1] : points[7];
        Point p2 = points[i];
        result += (p1.getX() - p2.getX()) * (p1.getY() + p2.getY());
    }
    return fabs(result) / 2.0;
}

Point Octagon::center() const {
    double x = 0.0;
    double y = 0.0;

    for (const Point& point : points) {
        x += point.getX();
        y += point.getY();
    }

    x /= 8;
    y /= 8;

    return Point(x, y);
}

Figure& Octagon::move(Figure &&other) noexcept {
    const Octagon *otherSquare = dynamic_cast<const Octagon*>(&other);
    for (size_t i = 0; i < 8; ++i) {
        points[i] = std::move(otherSquare->points[i]);
    }
    return *this;
}

Figure& Octagon::operator=(const Figure &other) {
    const Octagon *otherSquare = dynamic_cast<const Octagon*>(&other);
    for (size_t i = 0; i < 8; ++i) {
        points[i] = otherSquare->points[i];
    }
    return *this;
}

bool Octagon::operator==(const Figure &other) const {
    const Octagon *otherSquare = dynamic_cast<const Octagon*>(&other);
    for (size_t i = 0; i < 8; ++i) {
        if (points[i].getX() != otherSquare->points[i].getX() || points[i].getY() != otherSquare->points[i].getY()) {
            return 0;
        }
    }
    return 1;
}