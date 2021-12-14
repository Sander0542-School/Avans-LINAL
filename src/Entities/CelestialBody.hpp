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
                // POINTS
                {
                    _points.emplace_back(0, 1, -1); // 0
                    _points.emplace_back(1, 0, -1); // 1
                    _points.emplace_back(0, -1, -1); // 2
                    _points.emplace_back(-1, 0, -1); // 3

                    _points.emplace_back(0, 1, 1); // 4
                    _points.emplace_back(1, 0, 1); // 5
                    _points.emplace_back(0, -1, 1); // 6
                    _points.emplace_back(-1, 0, 1); // 7
                }

                // LINES
                {
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
                }

                // CENTER
                _center = {0, 0, 0};
            }
    };
}

#endif //LINAL_ASSESSMENT_CELESTIALBODY_HPP
