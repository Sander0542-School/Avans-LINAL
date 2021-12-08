#ifndef LINAL_OPDRACHTEN_ITRANSFORMABLE_HPP
#define LINAL_OPDRACHTEN_ITRANSFORMABLE_HPP

#include "Models/Matrix.hpp"

namespace linal::entities::common
{
    class ITransformable
    {
        public:
            virtual void Transform(const models::Matrix& matrix) = 0;
    };
}

#endif //LINAL_OPDRACHTEN_ITRANSFORMABLE_HPP
