#ifndef LINAL_ASSESSMENT_VECTOR_HPP
#define LINAL_ASSESSMENT_VECTOR_HPP

#include "Point.hpp"
#include "Common/Model.hpp"

#include <boost/format.hpp>

#include <cmath>
#include <sstream>
#include <string>

namespace linal::models
{
    class Vector : public common::Model<Vector>
    {
        public:
            double x;
            double y;
            double z;

            Vector(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z)
            {
            }

            Vector(const Point& from, const Point& to)
            {
                x = to.x - from.x;
                y = to.y - from.y;
                z = to.z - from.z;
            }

            [[nodiscard]] double Length() const
            {
                return sqrt(x * x + y * y + z * z);
            }

            [[nodiscard]] Vector Unit() const
            {
                auto distance = Length();
                return Vector{x / distance, y / distance, z / distance};
            }

            [[nodiscard]] double DotProduct(const Vector& rhs) const
            {
                return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
            }

            [[nodiscard]] Vector CrossProduct(const Vector& rhs) const
            {
                return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x};
            }

            [[nodiscard]] double Angle(const Vector& rhs) const
            {
                auto dotProduct = DotProduct(rhs);
                auto distanceSum = Length() * rhs.Length();

                return dotProduct / distanceSum;
            }

            [[nodiscard]] std::string ToString() const override
            {
                auto format = "%d";
                return "(" + boost::str(boost::format(format) % x) + "," + boost::str(boost::format(format) % y) + "," + boost::str(boost::format(format) % z) + ")";
            }

            Vector& operator+=(const Vector& rhs)
            {
                x += rhs.x;
                y += rhs.y;
                z += rhs.z;
                return *this;
            }

            Vector& operator-=(const Vector& rhs)
            {
                x -= rhs.x;
                y -= rhs.y;
                z -= rhs.z;
                return *this;
            }

            template<typename Numeric>
            Vector& operator*=(const Numeric& scalar)
            {
                x *= scalar;
                y *= scalar;
                z *= scalar;
                return *this;
            }

            friend Point operator+(const Point& rhs, const Vector& lhs)
            {
                return {rhs.x + lhs.x, rhs.y + lhs.y, rhs.z + lhs.z};
            }
    };
}

#endif //LINAL_ASSESSMENT_VECTOR_HPP
