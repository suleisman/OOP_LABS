#include <gtest/gtest.h>

#include "../include/figures.hpp"
#include <sstream>

TEST(OctagonTest, square) {
    std::stringstream ss;
    ss << "0 1\n1 3\n2 2\n3 4\n4 5\n5 3\n6 2\n1 0\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Octagon<double> o(points);
    ASSERT_EQ(o.square(), 13.0);
}

TEST(OctagonTest, center) {
    std::stringstream ss;
    ss << "0 1\n1 3\n2 2\n3 4\n4 5\n5 3\n6 2\n1 0\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Octagon<double> o(points);
    ASSERT_EQ(o.center().first, 2.75);
    ASSERT_EQ(o.center().second, 2.5);
}

TEST(TriangleTest, square) {
    std::stringstream ss;
    ss << "0 0\n0 9\n14 0\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Triangle<double> t(points);
    ASSERT_EQ(t.square(), 63.0);
}

TEST(TriangleTest, center) {
    std::stringstream ss;
    ss << "0 0\n0 9\n14 0\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Triangle<double> t(points);
    ASSERT_EQ(t.center().first, 14. / 3.);
    ASSERT_EQ(t.center().second, 3.0);
}

TEST(SquareTest, square) {
    std::stringstream ss;
    ss << "0 0\n0 3\n3 3\n3 0\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Square<double> s(points);
    ASSERT_EQ(s.square(), 9.0);
}

TEST(SquareTest, center) {
    std::stringstream ss;
    ss << "0 0\n0 3\n3 3\n3 0\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Square<double> s(points);
    ASSERT_EQ(s.center().first, 1.5);
    ASSERT_EQ(s.center().second, 1.5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}