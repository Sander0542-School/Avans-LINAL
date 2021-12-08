#ifndef LINAL_ASSESSMENT_CUBE_HPP
#define LINAL_ASSESSMENT_CUBE_HPP

#include "Common/Entity.hpp"

namespace linal::entities
{
    class Cube : public common::Entity
    {
        public:
            Cube()
            {
//                _points.emplace_back(0, 0, 0);
//                _points.emplace_back(6, 0, 0);
//                _points.emplace_back(6, 6, 0);
//                _points.emplace_back(0, 6, 0);
//                _points.emplace_back(0, 0, 6);
//                _points.emplace_back(6, 0, 6);
//                _points.emplace_back(6, 6, 6);
//                _points.emplace_back(0, 6, 6);

                _points.emplace_back(10, 10, -50);
                _points.emplace_back(10, 10, -70);
                _points.emplace_back(-10, 10, -70);
                _points.emplace_back(-10, 10, -50);
                _points.emplace_back(10, -10, -50);
                _points.emplace_back(10, -10, -70);
                _points.emplace_back(-10, -10, -70);
                _points.emplace_back(-10, -10, -50);

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

                _center = {3, 3, 3};
            }
    };
}

#endif //LINAL_ASSESSMENT_CUBE_HPP
