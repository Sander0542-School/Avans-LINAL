#include <gtest/gtest.h>
#include "Models/Vector.hpp"

#include <cmath>

using namespace linal::models;

TEST(VectorTests, TestDotProductMethod)
{
    Vector vectorV{2, 4, 0};
    Vector vectorW{4, 1, 0};

    ASSERT_EQ(vectorV.DotProduct(vectorW), 12);
}

TEST(VectorTests, TestAngleMethod)
{
    Vector vectorV{2, 4, 0};
    Vector vectorW{3, 2, 0};

    auto angle = vectorV.Angle(vectorW);
    angle = std::ceil(angle * 100) / 100;

    ASSERT_EQ(angle, 0.87);
}

TEST(VectorTests, TestCrossProductMethod)
{
    Vector vectorV{1, 0, 0};
    Vector vectorW{0, 1, 0};

    auto vectorX = vectorV.CrossProduct(vectorW);

    Vector vectorZ{0, 0, 1};
    ASSERT_TRUE(vectorX.x == vectorZ.x);
    ASSERT_TRUE(vectorX.y == vectorZ.y);
    ASSERT_TRUE(vectorX.z == vectorZ.z);
}