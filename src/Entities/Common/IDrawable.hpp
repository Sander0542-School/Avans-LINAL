#ifndef LINAL_OPDRACHTEN_IDRAWABLE_HPP
#define LINAL_OPDRACHTEN_IDRAWABLE_HPP

#include "Entities/Camera.hpp"
#include "Engine/Window.hpp"
#include "Models/Models.hpp"

namespace linal::entities::common
{
    class IDrawable
    {
        public:
            virtual void Draw(engine::Window& window, std::shared_ptr<entities::Camera> camera, const engine::Color& color = engine::Color::white()) = 0;
    };
}

#endif //LINAL_OPDRACHTEN_IDRAWABLE_HPP
