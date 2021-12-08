#ifndef LINAL_OPDRACHTEN_MATH_HPP
#define LINAL_OPDRACHTEN_MATH_HPP

#define _USE_MATH_DEFINES

#include <math.h>

namespace linal::utils
{
    class MathUtil
    {
        public:
            static double DegreesToRadians(double degrees)
            {
                return (degrees / 180) * M_PI;
            }

            static double RadiansToDegrees(double radians)
            {
                return (radians / M_PI) * 180;
            }
    };
}

#endif //LINAL_OPDRACHTEN_MATH_HPP
