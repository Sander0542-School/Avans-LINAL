#ifndef LINAL_ASSESSMENT_BOX_HPP
#define LINAL_ASSESSMENT_BOX_HPP

#include "Common/Stringable.hpp"

#include <boost/format.hpp>

namespace linal::models
{
    class Box : public common::Stringable
    {
        public:
            Box(double min, double max) : minX(max), minY(max), minZ(max), maxX(min), maxY(min), maxZ(min)
            {
            }

            double minX;
            double minY;
            double minZ;
            double maxX;
            double maxY;
            double maxZ;

            [[nodiscard]] bool Overlaps(const Box& rhs) const
            {
                return (minX < rhs.maxX && maxX > rhs.minX && minY < rhs.maxY && maxY > rhs.minY && minZ < rhs.maxZ && maxZ > rhs.minZ);
            }

            [[nodiscard]] std::string ToString() const override
            {
                auto format = "%10.2f";
                return "(" + boost::str(boost::format(format) % minX) + "," + boost::str(boost::format(format) % minY) + "," + boost::str(boost::format(format) % minZ) + boost::str(boost::format(format) % maxX) + "," + boost::str(boost::format(format) % maxY) + "," + boost::str(boost::format(format) % maxZ) + ")";
            }
    };
}

#endif //LINAL_ASSESSMENT_BOX_HPP
