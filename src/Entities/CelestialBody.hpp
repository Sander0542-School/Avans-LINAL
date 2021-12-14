#ifndef LINAL_ASSESSMENT_CELESTIALBODY_HPP
#define LINAL_ASSESSMENT_CELESTIALBODY_HPP

#include "Common/Entity.hpp"

namespace linal::entities
{
    class CelestialBody : public common::Entity
    {
        private:
            models::Matrix _rotateLeftMatrix = models::Matrix::Roll(2.5);
            models::Matrix _rotateRightMatrix = models::Matrix::Roll(-2.5);
            models::Matrix _scaleUpMatrix = models::Matrix::Scaling(1.05, 1.05, 1.05);
            models::Matrix _scaleDownMatrix = models::Matrix::Scaling(0.95, 0.95, 0.95);

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

            void OnUpdate() override
            {
                if (!engine::Input::AnyKey()) return;

                // ROTATION
                if (engine::Input::GetKey(engine::Input::KeyCode::C))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rotateLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::V))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rotateRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // SCALING
                if (engine::Input::GetKey(engine::Input::KeyCode::U))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _scaleUpMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::I))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _scaleDownMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
            }
    };
}

#endif //LINAL_ASSESSMENT_CELESTIALBODY_HPP
