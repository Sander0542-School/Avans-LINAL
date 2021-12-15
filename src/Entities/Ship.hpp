#ifndef LINAL_ASSESSMENT_SHIP_HPP
#define LINAL_ASSESSMENT_SHIP_HPP

#include "Common/Entity.hpp"

namespace linal::entities
{
    class Ship : public common::Entity
    {
        public:
            Ship()
            {
                _points.emplace_back(0, 0, -14);
                _points.emplace_back(-9.899, -9.899, -14);
                _points.emplace_back(9.899, -9.899, -14);
                _points.emplace_back(-9.899, 9.899, -14);
                _points.emplace_back(9.899, 9.899, -14);
                _points.emplace_back(-14, 0, 0);
                _points.emplace_back(14, 0, 0);
                _points.emplace_back(0, -14, 0);
                _points.emplace_back(0, 14, 0);
                _points.emplace_back(0, 0, 42);
                _points.emplace_back(-7, -7, 0);
                _points.emplace_back(7, -7, 0);
                _points.emplace_back(-7, 7, 0);
                _points.emplace_back(7, 7, 0);

                _lines.emplace_back(0, 1);
                _lines.emplace_back(0, 2);
                _lines.emplace_back(0, 3);
                _lines.emplace_back(0, 4);
                _lines.emplace_back(0, 5);
                _lines.emplace_back(0, 6);
                _lines.emplace_back(0, 7);
                _lines.emplace_back(0, 8);
                _lines.emplace_back(1, 10);
                _lines.emplace_back(2, 11);
                _lines.emplace_back(3, 12);
                _lines.emplace_back(4, 13);
                _lines.emplace_back(5, 7);
                _lines.emplace_back(5, 8);
                _lines.emplace_back(5, 9);
                _lines.emplace_back(6, 7);
                _lines.emplace_back(6, 8);
                _lines.emplace_back(6, 9);
                _lines.emplace_back(7, 9);
                _lines.emplace_back(8, 9);

                _center = {3, 3, 3};
            }
    };
}

#endif //LINAL_ASSESSMENT_SHIP_HPP
