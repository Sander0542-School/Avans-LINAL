#ifndef LINAL_OPDRACHTEN_IOBJECT_HPP
#define LINAL_OPDRACHTEN_IOBJECT_HPP

#include "IDrawable.hpp"
#include "IUpdatable.hpp"
#include "ITransformable.hpp"

#include "Models/Models.hpp"

#include <map>
#include <vector>

namespace linal::entities::common
{
    class Entity : public IDrawable, public ITransformable, public IUpdatable
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

            void Draw(engine::Window& window, const models::Point& worldCenter, int scale) override
            {
                for (const auto& pair: _lines)
                {
                    models::Vector line{_points[pair.first], _points[pair.second]};

                    window.RenderLine(_points[pair.first] * scale, line * scale, engine::Color::orange(), worldCenter);
                }
            }

            [[nodiscard]] models::Point Center() const
            {
                return _center;
            }
    };
}

#endif //LINAL_OPDRACHTEN_IOBJECT_HPP
