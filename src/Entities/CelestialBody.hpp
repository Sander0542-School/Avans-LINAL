#ifndef LINAL_ASSESSMENT_CELESTIALBODY_HPP
#define LINAL_ASSESSMENT_CELESTIALBODY_HPP

#include "Common/Entity.hpp"

namespace linal::entities
{
    class CelestialBody : public common::Entity
    {

        public:
            CelestialBody()
            {
                _points.emplace_back(-3, -3, -3);
                _points.emplace_back(3, -3, -3);
                _points.emplace_back(3, 3, -3);
                _points.emplace_back(-3, 3, -3);
                _points.emplace_back(-3, -3, 3);
                _points.emplace_back(3, -3, 3);
                _points.emplace_back(3, 3, 3);
                _points.emplace_back(-3, 3, 3);

                _lines.emplace_back(0, 1);
                _lines.emplace_back(1, 2);
                _lines.emplace_back(2, 3);
                _lines.emplace_back(3, 0);

                _lines.emplace_back(4, 5);
                _lines.emplace_back(5, 6);
                _lines.emplace_back(6, 7);
                _lines.emplace_back(7, 4);

                _lines.emplace_back(0, 4);
                _lines.emplace_back(1, 5);
                _lines.emplace_back(2, 6);
                _lines.emplace_back(3, 7);

                _center = {0, 0, 0};
            }

    };
}

#endif //LINAL_ASSESSMENT_CELESTIALBODY_HPP
