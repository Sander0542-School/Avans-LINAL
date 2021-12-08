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
                _points.emplace_back(-4, 0);
                _points.emplace_back(-1, 1);
                _points.emplace_back(0, 4);
                _points.emplace_back(1, 1);
                _points.emplace_back(4, 0);
                _points.emplace_back(1, -1);
                _points.emplace_back(0, -4);
                _points.emplace_back(-1, -1);

                _lines.emplace_back(0, 1);
                _lines.emplace_back(1, 2);
                _lines.emplace_back(2, 3);
                _lines.emplace_back(3, 4);
                _lines.emplace_back(4, 5);
                _lines.emplace_back(5, 6);
                _lines.emplace_back(6, 7);
                _lines.emplace_back(7, 0);
            }
    };
}

#endif //LINAL_OPDRACHTEN_STAR_HPP
