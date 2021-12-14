#ifndef LINAL_ASSESSMENT_MATRIX_HPP
#define LINAL_ASSESSMENT_MATRIX_HPP

#include "Vector.hpp"
#include "Common/Model.hpp"
#include "Utils/MathUtil.hpp"

#include <boost/format.hpp>

#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>

namespace linal::models
{
    namespace types
    {
        using matrix_row = std::vector<double>;
        using matrix_vector = std::vector<matrix_row>;
    }

    class MatrixRow
    {
        private:
            types::matrix_row& _row;

        public:
            MatrixRow(types::matrix_row& row) : _row{row}
            {
            }

            [[nodiscard]] size_t Columns() const
            {
                return _row.size();
            }

            const double& operator[](size_t column) const
            {
                if (column < 1 || column > Columns()) throw std::runtime_error("Invalid matrix column. Must been between 1 and " + std::to_string(Columns()));

                return _row[column - 1];
            }

            double& operator[](size_t column)
            {
                if (column < 1 || column > Columns()) throw std::runtime_error("Invalid matrix column. Must been between 1 and " + std::to_string(Columns()));

                return _row[column - 1];
            }
    };

    class Matrix : public common::Model<Matrix>
    {
        private:
            double _defaultValue;
            types::matrix_vector _matrix;

        public:
            Matrix(size_t rows, size_t columns, double defaultValue = 0) : _defaultValue(defaultValue)
            {
                if (rows < 1) throw std::runtime_error("A matrix requires at least one row");
                if (columns < 1) throw std::runtime_error("A matrix requires at least one column");

                _matrix = types::matrix_vector(rows, types::matrix_row(columns, _defaultValue));
            }

            Matrix(const Vector& vector, size_t rows = 4) : Matrix(rows, 1, 1)
            {
                _matrix[0][0] = vector.x;
                _matrix[1][0] = vector.y;
                _matrix[2][0] = vector.z;
            }

            Matrix(const Point& point, size_t rows = 4) : Matrix(rows, 1, 1)
            {
                _matrix[0][0] = point.x;
                _matrix[1][0] = point.y;
                _matrix[2][0] = point.z;
                _matrix[3][0] = point.w;
            }

            static Matrix Unit(size_t size)
            {
                Matrix matrix{size, size};

                for (int i = 0; i < size; ++i)
                {
                    matrix._matrix[i][i] = 1;
                }

                return matrix;
            }

            static Matrix Scaling(double x, double y, double z, size_t size = 4)
            {
                Matrix matrix = Unit(size);
                matrix._matrix[0][0] = x;
                matrix._matrix[1][1] = y;
                matrix._matrix[2][2] = z;

                return matrix;
            }

            static Matrix Translation(double x, double y, double z, size_t size = 4)
            {
                Matrix matrix = Unit(size);
                matrix._matrix[0][3] = x;
                matrix._matrix[1][3] = y;
                matrix._matrix[2][3] = z;

                return matrix;
            }

            static Matrix RotationX(double degrees, size_t size = 4)
            {
                auto radians = utils::MathUtil::DegreesToRadians(degrees);
                Matrix matrix = Unit(size);
                matrix._matrix[1][1] = cos(radians);
                matrix._matrix[2][1] = sin(radians);
                matrix._matrix[1][2] = -matrix._matrix[2][1];
                matrix._matrix[2][2] = matrix._matrix[1][1];

                return matrix;
            }

            static Matrix RotationY(double degrees, size_t size = 4)
            {
                auto radians = utils::MathUtil::DegreesToRadians(degrees);
                Matrix matrix = Unit(size);
                matrix._matrix[0][0] = cos(radians);
                matrix._matrix[0][2] = sin(radians);
                matrix._matrix[2][0] = -matrix._matrix[0][2];
                matrix._matrix[2][2] = matrix._matrix[0][0];

                return matrix;
            }

            static Matrix RotationZ(double degrees, size_t size = 4)
            {
                auto radians = utils::MathUtil::DegreesToRadians(degrees);
                Matrix matrix = Unit(size);
                matrix._matrix[0][0] = cos(radians);
                matrix._matrix[1][0] = sin(radians);
                matrix._matrix[0][1] = -matrix._matrix[1][0];
                matrix._matrix[1][1] = matrix._matrix[0][0];

                return matrix;
            }

            static Matrix Camera(const models::Vector& origin, const models::Vector& side, models::Vector top, models::Vector heading, size_t size = 4)
            {
                auto direction = heading.Unit();
                auto up = top.Unit();
                auto right = side.Unit();

                Matrix matrix = Unit(size);
                matrix._matrix[0][0] = right.x;
                matrix._matrix[0][1] = right.y;
                matrix._matrix[0][2] = right.z;
                matrix._matrix[0][3] = -right.DotProduct(origin);

                matrix._matrix[1][0] = up.x;
                matrix._matrix[1][1] = up.y;
                matrix._matrix[1][2] = up.z;
                matrix._matrix[0][3] = -up.DotProduct(origin);

                matrix._matrix[2][0] = direction.x;
                matrix._matrix[2][1] = direction.y;
                matrix._matrix[2][2] = direction.z;
                matrix._matrix[0][3] = -direction.DotProduct(origin);

                return matrix;
            }

            static Matrix Projection(double near, double far, double fovy, size_t size = 4)
            {
                double scale = near * tan(fovy * 0.5);
                Matrix matrix{size, size};
                matrix._matrix[0][0] = scale;
                matrix._matrix[1][1] = scale;
                matrix._matrix[2][2] = -far / (far - near);
                matrix._matrix[2][3] = -1;
                matrix._matrix[3][2] = -(far * near) / (far - near);

                return matrix;
            }

            [[nodiscard]] size_t Rows() const
            {
                return _matrix.size();
            }

            [[nodiscard]] size_t Columns() const
            {
                return _matrix[0].size();
            }

            MatrixRow operator[](size_t row)
            {
                if (row < 1 || row > Rows()) throw std::runtime_error("Invalid matrix row. Must been between 1 and " + std::to_string(Rows()));

                return {_matrix[row - 1]};
            }

            [[nodiscard]] std::string ToString() const override
            {
                std::stringstream string;
                for (const auto& row: _matrix)
                {
                    for (const double& item: row)
                    {
                        string << boost::format("%d") % item;
                        string << " ";
                    }
                    string << "\n";
                }

                return string.str();
            }

            Matrix& operator+=(const Matrix& rhs)
            {
                size_t lRows = _matrix.size();
                size_t lColumns = _matrix[0].size();
                size_t rRows = rhs._matrix.size();
                size_t rColumns = rhs._matrix[0].size();

                if (lRows != rRows || lColumns != rColumns) throw std::runtime_error("The matrix need to be the same size.");

                for (int i = 0; i < Rows(); ++i)
                {
                    for (int j = 0; j < Columns(); ++j)
                    {
                        _matrix[i][j] += rhs._matrix[i][j];
                    }
                }

                return *this;
            }

            Matrix& operator-=(const Matrix& rhs)
            {
                size_t lRows = _matrix.size();
                size_t lColumns = _matrix[0].size();
                size_t rRows = rhs._matrix.size();
                size_t rColumns = rhs._matrix[0].size();

                if (lRows != rRows || lColumns != rColumns) throw std::runtime_error("The matrix need to be the same size.");

                for (int i = 0; i < Rows(); ++i)
                {
                    for (int j = 0; j < Columns(); ++j)
                    {
                        _matrix[i][j] -= rhs._matrix[i][j];
                    }
                }

                return *this;
            }

            Matrix& operator*=(const Matrix& rhs)
            {
                if (Columns() != rhs.Rows()) throw std::runtime_error("The amount of columns on the left size need to be the same as the amount of rows on the right side.");

                Matrix newMatrix{Rows(), rhs.Columns()};

                for (int i = 0; i < Rows(); ++i)
                {
                    for (int j = 0; j < rhs.Columns(); ++j)
                    {
                        for (int k = 0; k < Columns(); ++k)
                        {
                            newMatrix._matrix[i][j] += _matrix[i][k] * rhs._matrix[k][j];
                        }
                    }
                }

                std::swap(*this, newMatrix);
                return *this;
            }

            friend Matrix operator*(Matrix lhs, const Matrix& rhs)
            {
                lhs *= rhs;
                return lhs;
            }

            template<typename Numeric>
            Matrix& operator*=(const Numeric& scalar)
            {
                for (int i = 0; i < Rows(); ++i)
                {
                    for (int j = 0; j < Columns(); ++j)
                    {
                        _matrix[i][j] *= scalar;
                    }
                }

                return *this;
            }

            friend Vector operator*(const Matrix& lhs, const Vector& rhs)
            {
                Matrix matrix = lhs * Matrix(rhs, lhs.Columns());

                return {matrix._matrix[0][0], matrix._matrix[1][0], matrix._matrix[2][0]};
            }

            friend Vector operator*(const Vector& lhs, const Matrix& rhs)
            {
                return rhs * lhs;
            }

            friend Point operator*(const Matrix& lhs, const Point& rhs)
            {
                Matrix matrix = lhs * Matrix(rhs, lhs.Columns());

                return {matrix._matrix[0][0], matrix._matrix[1][0], matrix._matrix[2][0], matrix._matrix[3][0]};
            }

            friend Point operator*(const Point& lhs, const Matrix& rhs)
            {
                return rhs * lhs;
            }
    };
}

#endif //LINAL_ASSESSMENT_MATRIX_HPP
