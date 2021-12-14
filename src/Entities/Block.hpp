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
