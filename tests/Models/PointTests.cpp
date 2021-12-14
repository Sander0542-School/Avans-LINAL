#include <gtest/gtest.h>
#include "Models/Point.hpp"

using namespace linal::models;

TEST(PointTests, TestPointAdditionAssignmentOperator)
{
    Point pointA{10, 10, 10};
    Point pointB{-5, 5, 0};

    pointA += pointB;

    Point pointZ{5, 15, 10};
    ASSERT_EQ(pointA.x, pointZ.x);
    ASSERT_EQ(pointA.y, pointZ.y);
    ASSERT_EQ(pointA.z, pointZ.z);
}

TEST(PointTests, TestPointAdditionSubtractionOperator)
{
    Point pointA{10, 10, 10};
    Point pointB{-5, 5, 0};

    pointA -= pointB;

    Point pointZ{15, 5, 10};
    ASSERT_EQ(pointA.x, pointZ.x);
    ASSERT_EQ(pointA.y, pointZ.y);
    ASSERT_EQ(pointA.z, pointZ.z);
}