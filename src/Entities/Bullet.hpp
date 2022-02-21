#ifndef LINAL_ASSESSMENT_BULLET_H
#define LINAL_ASSESSMENT_BULLET_H

#include "Common/Entity.hpp"

namespace linal::entities
{
    class Bullet : public common::Entity
    {
        public:
            Bullet(const models::Point& point1, const models::Point& point2)
            {
                // POINTS
                {
                    // NOSE
                    _points.emplace_back(point1);
                    _points.emplace_back(point2);
                }

                // LINES
                {
                    _lines.emplace_back(0, 1);
                }

                // CENTER
                _center = {0, 0, 0, 5};
            }

            void OnUpdate() override
            {
                const auto& fromPoint = _points[0];
                const auto& toPoint = _points[1];
                models::Vector direction = models::Vector{fromPoint, toPoint}.Unit() * 0.1;

                this->Transform(models::Matrix::Translation(direction.x, direction.y, direction.z));
            }
    };
}

#endif //LINAL_ASSESSMENT_BULLET_H
