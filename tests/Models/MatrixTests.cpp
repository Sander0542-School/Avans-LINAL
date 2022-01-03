#include <gtest/gtest.h>
#include "Models/Matrix.hpp"

using namespace linal::models;

TEST(MatrixTests, TestTranslationTemplate)
{
    Matrix matrixA = Matrix::Translation(3, 5, 7);
    Matrix matrixB{4, 4};
    matrixB[1][1] = 1;
    matrixB[1][2] = 0;
    matrixB[1][3] = 0;
    matrixB[1][4] = 3; // X
    matrixB[2][1] = 0;
    matrixB[2][2] = 1;
    matrixB[2][3] = 0;
    matrixB[2][4] = 5; // Y
    matrixB[3][1] = 0;
    matrixB[3][2] = 0;
    matrixB[3][3] = 1;
    matrixB[3][4] = 7; // Z
    matrixB[4][1] = 0;
    matrixB[4][2] = 0;
    matrixB[4][3] = 0;
    matrixB[4][4] = 1;

    ASSERT_EQ(matrixA, matrixB);
}

TEST(MatrixTests, TestScalingTemplate)
{
    Matrix matrixA = Matrix::Scaling(3, 5, 7);
    Matrix matrixB{4, 4};
    matrixB[1][1] = 3; // X
    matrixB[1][2] = 0;
    matrixB[1][3] = 0;
    matrixB[1][4] = 0;
    matrixB[2][1] = 0;
    matrixB[2][2] = 5; // Y
    matrixB[2][3] = 0;
    matrixB[2][4] = 0;
    matrixB[3][1] = 0;
    matrixB[3][2] = 0;
    matrixB[3][3] = 7; // Z
    matrixB[3][4] = 0;
    matrixB[4][1] = 0;
    matrixB[4][2] = 0;
    matrixB[4][3] = 0;
    matrixB[4][4] = 1;

    ASSERT_EQ(matrixA, matrixB);
}

TEST(MatrixTests, TestYawRotation)
{
    Point pointA{1, 1, -1};

    Matrix matrix = Matrix::Yaw(90);
    auto pointB = matrix * Point{1, 1, 1};

    ASSERT_EQ(pointA.z, round(pointB.z));
}

TEST(MatrixTests, TestPitchRotation)
{
    Point pointA{1, -1, 1};

    Matrix matrix = Matrix::Pitch(90);
    auto pointB = matrix * Point{1, 1, 1};

    ASSERT_EQ(pointA.y, round(pointB.y));
}

TEST(MatrixTests, TestRollRotation)
{
    Point pointA{-1, 1, 1};

    Matrix matrix = Matrix::Roll(90);
    auto pointB = matrix * Point{1, 1, 1};

    ASSERT_EQ(pointA.x, round(pointB.x));
}

TEST(MatrixTests, TestRotationRotation)
{
    Point pointA{1, -1, 1};

    Matrix matrix = Matrix::Yaw(90) * Matrix::Pitch(90) * Matrix::Roll(90);
    auto pointB = matrix * Point{1, 1, 1};

    ASSERT_EQ(pointA.x, round(pointB.x));
    ASSERT_EQ(pointA.y, round(pointB.y));
    ASSERT_EQ(pointA.z, round(pointB.z));
}

TEST(MatrixTests, TestMatrixOperatorAddition)
{
    Matrix matrixA{2, 3};
    matrixA[1][1] = 2;
    matrixA[1][2] = 0;
    matrixA[1][3] = -1;
    matrixA[2][1] = -3;
    matrixA[2][2] = 2;
    matrixA[2][3] = 4;

    Matrix matrixB{2, 3};
    matrixB[1][1] = -2;
    matrixB[1][2] = 4;
    matrixB[1][3] = 3;
    matrixB[2][1] = 3;
    matrixB[2][2] = 2;
    matrixB[2][3] = 0;

    Matrix matrixC{2, 3};
    matrixC[1][1] = 0;
    matrixC[1][2] = 4;
    matrixC[1][3] = 2;
    matrixC[2][1] = 0;
    matrixC[2][2] = 4;
    matrixC[2][3] = 4;

    ASSERT_EQ(matrixA + matrixB, matrixC);
}

TEST(MatrixTests, TestMatrixOperatorSubtraction)
{
    Matrix matrixA{2, 3};
    matrixA[1][1] = 2;
    matrixA[1][2] = 0;
    matrixA[1][3] = -1;
    matrixA[2][1] = -3;
    matrixA[2][2] = 2;
    matrixA[2][3] = 4;

    Matrix matrixB{2, 3};
    matrixB[1][1] = -2;
    matrixB[1][2] = 4;
    matrixB[1][3] = 3;
    matrixB[2][1] = 3;
    matrixB[2][2] = 2;
    matrixB[2][3] = 0;

    Matrix matrixC{2, 3};
    matrixC[1][1] = 4;
    matrixC[1][2] = -4;
    matrixC[1][3] = -4;
    matrixC[2][1] = -6;
    matrixC[2][2] = 0;
    matrixC[2][3] = 4;

    ASSERT_EQ(matrixA - matrixB, matrixC);
}

TEST(MatrixTests, TestMatrixOperatorMultiplication)
{
    Matrix matrixA{2, 2};
    matrixA[1][1] = 5;
    matrixA[1][2] = 7;
    matrixA[2][1] = 6;
    matrixA[2][2] = 8;

    Matrix matrixB{2, 2};
    matrixB[1][1] = 1;
    matrixB[1][2] = 2;
    matrixB[2][1] = 3;
    matrixB[2][2] = 4;

    Matrix matrixC{2, 2};
    matrixC[1][1] = 26;
    matrixC[1][2] = 38;
    matrixC[2][1] = 30;
    matrixC[2][2] = 44;

    Matrix matrixD{2, 2};
    matrixD[1][1] = 17;
    matrixD[1][2] = 23;
    matrixD[2][1] = 39;
    matrixD[2][2] = 53;

    ASSERT_EQ(matrixA * matrixB, matrixC);
    ASSERT_EQ(matrixB * matrixA, matrixD);
}

TEST(MatrixTests, TestMatrixOperatorMultiplicationNumber)
{
    Matrix matrixA{2, 3};
    matrixA[1][1] = 2;
    matrixA[1][2] = 0;
    matrixA[1][3] = -1;
    matrixA[2][1] = -3;
    matrixA[2][2] = 2;
    matrixA[2][3] = 4;

    Matrix matrixB{2, 3};
    matrixB[1][1] = 4;
    matrixB[1][2] = 0;
    matrixB[1][3] = -2;
    matrixB[2][1] = -6;
    matrixB[2][2] = 4;
    matrixB[2][3] = 8;

    ASSERT_EQ(matrixA * 2, matrixB);
}

TEST(MatrixTests, TestMatrixScalingTranslation)
{
    Matrix matrixA = Matrix::Scaling(2, 3, 1);
    Matrix matrixB = Matrix::Translation(2, 2, 1);

    Matrix matrixC{4, 4};
    matrixC[1][1] = 2;
    matrixC[1][2] = 0;
    matrixC[1][3] = 0;
    matrixC[1][4] = 4;
    matrixC[2][1] = 0;
    matrixC[2][2] = 3;
    matrixC[2][3] = 0;
    matrixC[2][4] = 6;
    matrixC[3][1] = 0;
    matrixC[3][2] = 0;
    matrixC[3][3] = 1;
    matrixC[3][4] = 1;
    matrixC[4][1] = 0;
    matrixC[4][2] = 0;
    matrixC[4][3] = 0;
    matrixC[4][4] = 1;

    ASSERT_EQ(matrixA * matrixB, matrixC);
}