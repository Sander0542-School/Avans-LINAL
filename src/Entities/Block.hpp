#ifndef LINAL_OPDRACHTEN_STAR_HPP
#define LINAL_OPDRACHTEN_STAR_HPP

#include "Common/Entity.hpp"
#include "Engine/Input.hpp"

namespace linal::entities
{
    class Block : public common::Entity
    {
        private:
            models::Matrix rotateLeftMatrix = models::Matrix::Roll(2.5);
            models::Matrix rotateRightMatrix = models::Matrix::Roll(-2.5);

        public:
            Block()
            {
                // POINTS
                _points.emplace_back(0, 0, 0); // 00
                _points.emplace_back(6, 0, 0); // 01
                _points.emplace_back(0, 4, 0); // 02
                _points.emplace_back(1, 4, 0); // 03
                _points.emplace_back(1, 1, 0); // 04
                _points.emplace_back(6, 1, 0); // 05
                _points.emplace_back(6, 1, 1); // 06
                _points.emplace_back(1, 4, 1); // 07
                _points.emplace_back(0, 4, 4); // 08
                _points.emplace_back(1, 4, 3); // 09
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

            void OnUpdate() override
            {
                if (!engine::Input::AnyKey()) return;

                if (engine::Input::GetKey(engine::Input::KeyCode::C))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * rotateLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::V))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * rotateRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
            }
    };
}

#endif //LINAL_OPDRACHTEN_STAR_HPP
