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