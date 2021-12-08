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
            models::Matrix _projection = models::Matrix::Projection(0.1, 1000, 60);

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
                window.SetDrawColor(color);
                for (const auto& pair: _lines)
                {
                    auto beginPoint = _points[pair.first] * _projection;
                    auto endPoint = _points[pair.second] * _projection;

                    if (beginPoint.w <= 0 || endPoint.w <= 0)
                        continue;

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
