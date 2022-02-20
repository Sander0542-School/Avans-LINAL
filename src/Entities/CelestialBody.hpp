#ifndef LINAL_ASSESSMENT_CELESTIALBODY_HPP
#define LINAL_ASSESSMENT_CELESTIALBODY_HPP

#include "Common/Entity.hpp"

namespace linal::entities
{
    class CelestialBody : public common::Entity
    {
        private:
            double initialLength;
            bool goingUp = true;
            bool _isColliding;

            models::Matrix _scaleUpMatrix = models::Matrix::Scaling(1.03, 1.03, 1.03);
            models::Matrix _scaleDownMatrix = models::Matrix::Scaling(0.97, 0.97, 0.97);

            std::vector<std::shared_ptr<entities::common::IDrawable>>& _drawables;

        public:
            CelestialBody(std::vector<std::shared_ptr<entities::common::IDrawable>>& drawables) : _drawables(drawables)
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

                initialLength = models::Vector{_points[0], _points[1]}.Length();
            }

            void OnUpdate() override
            {
                double scale = 100.0 / initialLength * models::Vector{_points[0], _points[1]}.Length();

                if (scale >= 125)
                {
                    goingUp = false;
                }
                else if (scale <= 75)
                {
                    goingUp = true;
                }

                auto center = this->Center();
                if (goingUp)
                {
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _scaleUpMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                else
                {
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _scaleDownMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                auto boxA = BoundingBox();

                _isColliding = false;
                for (const auto& drawable: _drawables)
                {
                    auto entity = std::dynamic_pointer_cast<common::Entity>(drawable);
                    for (const models::Point& point: entity->_points)
                    {
                        if (point.x > minX && point.x < maxX && point.y > minY && point.y < maxY && point.z > minZ && point.z < maxZ)
                        {
                            _isColliding = true;
                            break;
                        }
                    }
                }
            }

            void Draw(engine::Window& window, std::shared_ptr<entities::Camera> camera, const engine::Color& color) override
            {
                Entity::Draw(window, camera, _isColliding ? engine::Color::red() : engine::Color::blue());
            }
    };
}

#endif //LINAL_ASSESSMENT_CELESTIALBODY_HPP
