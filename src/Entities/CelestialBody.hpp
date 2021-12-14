#ifndef LINAL_ASSESSMENT_CELESTIALBODY_HPP
#define LINAL_ASSESSMENT_CELESTIALBODY_HPP

#include "Common/Entity.hpp"

namespace linal::entities
{
    class CelestialBody : public common::Entity
    {
        private:
            models::Matrix _rollLeftMatrix = models::Matrix::Roll(2.5);
            models::Matrix _rollRightMatrix = models::Matrix::Roll(-2.5);
            models::Matrix _yawLeftMatrix = models::Matrix::Yaw(2.5);
            models::Matrix _yawRightMatrix = models::Matrix::Yaw(-2.5);
            models::Matrix _pitchLeftMatrix = models::Matrix::Pitch(2.5);
            models::Matrix _pitchRightMatrix = models::Matrix::Pitch(-2.5);
            models::Matrix _scaleUpMatrix = models::Matrix::Scaling(1.05, 1.05, 1.05);
            models::Matrix _scaleDownMatrix = models::Matrix::Scaling(0.95, 0.95, 0.95);

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

            void OnUpdate() override
            {
                if (!engine::Input::AnyKey()) return;

                // ROTATION: ROLL
                if (engine::Input::GetKey(engine::Input::KeyCode::C))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rollLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::V))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rollRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                // ROTATION: ROLL
                if (engine::Input::GetKey(engine::Input::KeyCode::C))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rollLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::V))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rollRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // ROTATION: YAW
                if (engine::Input::GetKey(engine::Input::KeyCode::B))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _yawLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::N))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _yawRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // ROTATION: PITCH
                if (engine::Input::GetKey(engine::Input::KeyCode::O))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _pitchLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::P))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _pitchRightMatrix  * models::Matrix::Translation(-center.x, -center.y, -center.z));
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
