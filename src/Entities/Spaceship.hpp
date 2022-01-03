#ifndef LINAL_ASSESSMENT_SPACESHIP_H
#define LINAL_ASSESSMENT_SPACESHIP_H

#include "Common/Entity.hpp"

namespace linal::entities
{
    class Spaceship : public common::Entity
    {
        public:
            Spaceship()
            {
                // POINTS
                {
                    // NOSE
                    _points.emplace_back(0, 3, 0); // 0 - tip of nose
                    _points.emplace_back(-1, 2, 0); // 1 - left front
                    _points.emplace_back(-1, 2, 1); // 2 - left front elevate
                    _points.emplace_back(1, 2, 0); // 3 - right front
                    _points.emplace_back(1, 2, 1); // 4 - right front elevate


                    // FRONT HULL TO WINGS
                    _points.emplace_back(-1, 1, 0); // 5 - left front
                    _points.emplace_back(-1, 1, 1); // 6 - left front elevate
                    _points.emplace_back(1, 1, 0); // 7 - right front
                    _points.emplace_back(1, 1, 1); // 8 - right front elevate

                    // WINGS AND HULL
                    _points.emplace_back(-3, -1, 0); // 9 - left wing front tip
                    _points.emplace_back(-2, -2, 0); // 10 - left wing back tip
                    _points.emplace_back(3, -1, 0); // 11 - right wing front tip
                    _points.emplace_back(2, -2, 0); // 12 - right wing back tip
                    _points.emplace_back(-1, -1, 0); // 13 - left wing attach
                    _points.emplace_back(-1, -1, 1); // 14 - left wing attach elevate
                    _points.emplace_back(1, -1, 0); // 15 - right wing attach
                    _points.emplace_back(1, -1, 1); // 16 - right wing attach elevate


                    // TALE
                    _points.emplace_back(-1, -3, 1); // 17 - tip of left tale
                    _points.emplace_back(1, -3, 1); // 18 - tip of right tale
                    _points.emplace_back(0, -2, 0); // 19 - inner tale
                    _points.emplace_back(0, -2, 1); // 20 - inner tale elevate

                    // VERTICAL WING
                    _points.emplace_back(0, 1, 1); // 21 - front anchor
                    _points.emplace_back(0, 0, 2); // 22 - tip
                    _points.emplace_back(0, -1, 1); // 23 - back anchor
                }

                // LINES
                {
                    // NOSE
                    _lines.emplace_back(0, 1);
                    _lines.emplace_back(0, 2);
                    _lines.emplace_back(0, 3);
                    _lines.emplace_back(0, 4);

                    // FRONT HULL TO WINGS
                    _lines.emplace_back(1, 5);
                    _lines.emplace_back(2, 6);
                    _lines.emplace_back(3, 7);
                    _lines.emplace_back(4, 8);

                    // LEFT WINGS
                    _lines.emplace_back(5, 9);
                    _lines.emplace_back(6, 9);
                    _lines.emplace_back(9, 10);
                    _lines.emplace_back(5, 13);
                    _lines.emplace_back(6, 14);
                    _lines.emplace_back(5, 6);
                    _lines.emplace_back(13, 14);

                    // RIGHT WINGS
                    _lines.emplace_back(7, 11);
                    _lines.emplace_back(8, 11);
                    _lines.emplace_back(11, 12);
                    _lines.emplace_back(7, 15);
                    _lines.emplace_back(8, 16);
                    _lines.emplace_back(7, 8);
                    _lines.emplace_back(15, 16);

                    // WINGS ATTACHMENT
                    _lines.emplace_back(10, 13);
                    _lines.emplace_back(10, 14);
                    _lines.emplace_back(12, 15);
                    _lines.emplace_back(12, 16);

                    // LEFT TALE
                    _lines.emplace_back(13, 17);
                    _lines.emplace_back(14, 17);
                    _lines.emplace_back(15, 18);
                    _lines.emplace_back(16, 18);

                    // RIGHT TALE
                    _lines.emplace_back(17, 19);
                    _lines.emplace_back(17, 20);
                    _lines.emplace_back(18, 19);
                    _lines.emplace_back(18, 20);

                    // VERTICAL WING
                    _lines.emplace_back(21, 22);
                    _lines.emplace_back(22, 23);
                }

                // CENTER
                _center = {0, 0, 1};
            }

            void OnUpdate() override
            {
                // ROTATION: ROLL
                if (engine::Input::GetKey(engine::Input::KeyCode::Q))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rollLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::E))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rollRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // ROTATION: YAW
                if (engine::Input::GetKey(engine::Input::KeyCode::A))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _yawLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::D))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _yawRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // ROTATION: PITCH
                if (engine::Input::GetKey(engine::Input::KeyCode::W))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _pitchLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::S))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _pitchRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // MOMEMENT
                if (engine::Input::GetKey(engine::Input::KeyCode::LEFT_SHIFT) || engine::Input::GetKey(engine::Input::KeyCode::RIGHT_SHIFT))
                {
                    const auto& fromPoint = _points[19];
                    const auto& toPoint = _points[0];
                    models::Vector direction = models::Vector{fromPoint, toPoint}.Unit() * 0.1;

                    this->Transform(models::Matrix::Translation(direction.x, direction.y, direction.z));
                }
            }
    };
}

#endif //LINAL_ASSESSMENT_SPACESHIP_H
