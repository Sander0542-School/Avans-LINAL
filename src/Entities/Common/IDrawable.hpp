#ifndef LINAL_OPDRACHTEN_IDRAWABLE_HPP
#define LINAL_OPDRACHTEN_IDRAWABLE_HPP

#include "Engine/Window.hpp"
#include "Models/Models.hpp"

namespace linal::entities::common
{
    class IDrawable
    {
        public:
            virtual void Draw(engine::Window& window, const models::Point& worldCenter, int scale) = 0;
    };
}

#endif //LINAL_OPDRACHTEN_IDRAWABLE_HPP
