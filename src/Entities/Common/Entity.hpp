#ifndef LINAL_OPDRACHTEN_IOBJECT_HPP
#define LINAL_OPDRACHTEN_IOBJECT_HPP

#include "IDrawable.hpp"
#include "ITransformable.hpp"

#include "Models/Models.hpp"

#include <map>
#include <vector>

namespace linal::entities::common
{
    class Entity : public IDrawable, public ITransformable
    {
        protected:
            models::Point _center{0, 0, 0};
            std::vector<models::Point> _points{};
            std::vector<std::pair<size_t, size_t>> _lines{};

        public:
            void Transform(const models::Matrix& matrix) override
            {
                _center = matrix * _center;
                for (auto& point: _points)
                {
                    point = matrix * point;
                }
            }

            void Draw(engine::Window& window, const engine::Color& color) override
            {
                auto windowCenter = window.Size() * 0.5;

                auto cameraMatrix = models::Matrix::Camera({0, 20, 0}, {-1, 0, 0}, {0, 1, 0}, {0, 0, -1});
                auto projectionMatrix = models::Matrix::Projection(10, 1000, 90);

                std::vector<models::Point> points;

                for (const auto& point: _points)
                {
                    auto cameraPoint = projectionMatrix * cameraMatrix * point;

                    auto x = windowCenter.x + (cameraPoint.x / cameraPoint.w) * windowCenter.x;
                    auto y = windowCenter.y + (cameraPoint.y / cameraPoint.w) * windowCenter.y;

                    points.emplace_back(x, y, -cameraPoint.z);
                }

                window.SetDrawColor(color);
                for (const auto&[from, to]: _lines)
                {
                    const auto& beginPoint = points[from];
                    const auto& endPoint = points[to];

                    window.RenderLine(beginPoint, endPoint);
                }
            }

            [[nodiscard]] models::Point Center() const
            {
                return _center;
            }
    };
}

#endif //LINAL_OPDRACHTEN_IOBJECT_HPP
