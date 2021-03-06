#ifndef LINAL_ASSESSMENT_POINT_HPP
#define LINAL_ASSESSMENT_POINT_HPP

#include "Common/Model.hpp"

#include <boost/format.hpp>

namespace linal::models
{
    class Point : public common::Model<Point>
    {
        public:
            double x;
            double y;
            double z;
            double w;

            Point(double x = 0, double y = 0, double z = 0) : Point(x, y, z, 1)
            {
            }

            Point(double x, double y, double z, double w) : x(x), y(y), z(z), w(w)
            {
            }

            Point& operator+=(const Point& rhs)
            {
                x += rhs.x;
                y += rhs.y;
                z += rhs.z;
                return *this;
            }

            Point& operator-=(const Point& rhs)
            {
                x -= rhs.x;
                y -= rhs.y;
                z -= rhs.z;
                return *this;
            }

            template<typename Numeric>
            Point& operator*=(const Numeric& scalar)
            {
                x *= scalar;
                y *= scalar;
                z *= scalar;
                return *this;
            }

            [[nodiscard]] std::string ToString() const override
            {
                auto format = "%d";
                return "(" + boost::str(boost::format(format) % x) + "," + boost::str(boost::format(format) % y) + "," + boost::str(boost::format(format) % z) + ")";
            }

            bool operator==(const Point& rhs) const
            {
                return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
            }

            bool operator!=(const Point& rhs) const
            {
                return !(rhs == *this);
            }
    };
}

#endif //LINAL_ASSESSMENT_POINT_HPP
