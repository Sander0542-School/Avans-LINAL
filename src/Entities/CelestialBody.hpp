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

            models::Matrix _scaleUpMatrix = models::Matrix::Scaling(1.03, 1.03, 1.03);
            models::Matrix _scaleDownMatrix = models::Matrix::Scaling(0.97, 0.97, 0.97);

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

                initialLength = models::Vector{_points[0], _points[1]}.Length();
            }

            void OnUpdate() override
            {
                double scale = 100.0 / initialLength * models::Vector{_points[0], _points[1]}.Length();

                if (scale >= 125) {
                    goingUp = false;
                }
                else if (scale <= 75) {
                    goingUp = true;
                }

                auto center = this->Center();
                if (goingUp) {
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _scaleUpMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                } else {
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _scaleDownMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
            }
    };
}

#endif //LINAL_ASSESSMENT_CELESTIALBODY_HPP
