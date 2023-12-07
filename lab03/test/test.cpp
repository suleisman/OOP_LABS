#include "src/list.hpp"
#include "src/octagon.hpp"
#include "src/point.hpp"
#include "src/square.hpp"
#include "src/triangle.hpp"
#include <gtest/gtest.h>
#include <cmath>

TEST(octagon, copy) {
    std::stringstream stream;
    stream << "0 1\n1 3\n2 2\n3 4\n4 5\n5 3\n6 2\n1 0\n";
    Octagon o(stream);
    Octagon o1(o);
    ASSERT_TRUE(o == o1);
}

TEST(octagon1, square) {
    std::stringstream stream;
    stream << "0 1\n1 3\n2 2\n3 4\n4 5\n5 3\n6 2\n1 0\n";
    Octagon o(stream);
    ASSERT_EQ(o.square(), 13);
}

TEST(octagon3, center) {
    std::stringstream stream;
    stream << "0 1\n1 3\n2 2\n3 4\n4 5\n5 3\n6 2\n1 0\n";
    Octagon o(stream);
    ASSERT_EQ(o.center().getX(), 2.75);
    ASSERT_EQ(o.center().getY(), 2.5);
}

TEST(square, copy) {
    std::stringstream stream;
    stream << "0 1\n1 3\n2 2\n3 4\n";
    Octagon s(stream);
    Octagon s1(s);
    ASSERT_TRUE(s == s1);
}

TEST(square, square) {
    std::stringstream stream;
    stream << "0 0\n0 3\n3 3\n3 0\n";
    Square s(stream);
    ASSERT_EQ(s.square(), 9);
}

TEST(square1, center) {
    std::stringstream stream;
    stream << "0 0\n0 3\n3 3\n3 0\n";
    Square s(stream);
    ASSERT_EQ(s.center().getX(), 1.5);
    ASSERT_EQ(s.center().getY(), 1.5);
}

TEST(square2, center) {
    std::stringstream stream;
    stream << "0 0\n0 5\n5 5\n5 0\n";
    Square s(stream);
    ASSERT_EQ(s.center().getX(), 2.5);
    ASSERT_EQ(s.center().getY(), 2.5);
}

TEST(triangle, copy) {
    std::stringstream stream;
    stream << "0 1\n1 3\n2 2\n";
    Octagon t(stream);
    Octagon t1(t);
    ASSERT_TRUE(t == t1);
}

TEST(triangle, square) {
    std::stringstream stream;
    stream << "-3 0\n0 5\n3 0\n";
    Triangle t(stream);
    ASSERT_EQ(t.square(), std::sqrt(3) * 9);
}

TEST(triangle1, center) {
    std::stringstream stream;
    stream << "-3 0\n0 5\n3 0\n";
    Triangle t(stream);
    ASSERT_EQ(t.center().getX(), 0);
    ASSERT_EQ(t.center().getY(), 5./3.);
}

TEST(triangle2, center) {
    std::stringstream stream;
    stream << "-4 0\n0 7\n4 0\n";
    Triangle t(stream);
    ASSERT_EQ(t.center().getX(), 0);
    ASSERT_EQ(t.center().getY(), 7./3.);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}