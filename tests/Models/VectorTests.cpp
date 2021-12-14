#include <gtest/gtest.h>
#include "Models/Vector.hpp"

using namespace linal::models;

TEST(VectorTests, DotProductMethod)
{
    Vector vectorV{2, 4, 0};
    Vector vectorW{4, 1, 0};

    ASSERT_TRUE(vectorV.DotProduct(vectorW) == 12);
}