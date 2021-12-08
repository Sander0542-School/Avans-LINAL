#ifndef LINAL_OPDRACHTEN_STAR_HPP
#define LINAL_OPDRACHTEN_STAR_HPP

#include "Common/Entity.hpp"

namespace linal::entities
{
    class Block : public common::Entity
    {
        public:
            Block()
            {
                // POINTS
                _points.emplace_back(0, 0, 0); // 0
                _points.emplace_back(6, 0, 0); // 1
                _points.emplace_back(0, 4, 0); // 2
                _points.emplace_back(1, 4, 0); // 3
                _points.emplace_back(1, 1, 0); // 4
                _points.emplace_back(6, 1, 0); // 5
                _points.emplace_back(6, 1, 1); // 6
                _points.emplace_back(1, 4, 1); // 7
                _points.emplace_back(0, 4, 4); // 8
                _points.emplace_back(1, 4, 3); // 9
                _points.emplace_back(1, 1, 1); // 10
                _points.emplace_back(6, 0, 4); // 11
                _points.emplace_back(6, 4, 4); // 12
                _points.emplace_back(6, 4, 3); // 13
                _points.emplace_back(6, 1, 3); // 14
                _points.emplace_back(1, 1, 3); // 15
                _points.emplace_back(1, 1, 2); // 16
                _points.emplace_back(1, 4, 2); // 17
                _points.emplace_back(6, 1, 2); // 18


                // LINES
                _lines.emplace_back(0, 1);
                _lines.emplace_back(0, 2);
                _lines.emplace_back(2, 3);
                _lines.emplace_back(3, 4);
                _lines.emplace_back(4, 5);
                _lines.emplace_back(5, 1);
                _lines.emplace_back(6, 7);
                _lines.emplace_back(5, 6);
                _lines.emplace_back(3, 7);
                _lines.emplace_back(17, 7);
                _lines.emplace_back(17, 9);
                _lines.emplace_back(2, 8);
                _lines.emplace_back(4, 10);
                _lines.emplace_back(7, 10);
                _lines.emplace_back(6, 10);
                _lines.emplace_back(6, 18);
                _lines.emplace_back(14, 18);
                _lines.emplace_back(14, 13);
                _lines.emplace_back(12, 13);
                _lines.emplace_back(9, 13);
                _lines.emplace_back(9, 15);
                _lines.emplace_back(16, 15);
                _lines.emplace_back(12, 8);
                _lines.emplace_back(17, 18);
                _lines.emplace_back(16, 18);
                _lines.emplace_back(1, 11);
                _lines.emplace_back(12, 11);

            }
    };
}

#endif //LINAL_OPDRACHTEN_STAR_HPP
