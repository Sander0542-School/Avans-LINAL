#include "Engine/InputManager.hpp"
#include "Engine/Input.hpp"
#include "Engine/Window.hpp"
#include "Models/Models.hpp"

#include "Entities/Entities.hpp"

#include <vector>

using namespace linal::engine;
using namespace linal::models;
using namespace linal::entities;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

int main(int argc, char* args[])
{
    Window window{"LINAL Assessment", {10, 50}, {WINDOW_WIDTH, WINDOW_HEIGHT}};

    std::vector<std::shared_ptr<linal::entities::common::IDrawable>> drawables;
    auto star = std::make_shared<Cube>();
    drawables.push_back(star);

    while (true)
    {
        if (!InputManager::GetInstance().Update()) break;

        window.Clear();

        // transform models

        for (const auto& drawable: drawables)
        {
            drawable->Draw(window);
        }

        window.SwapBuffers();

        SDL_Delay(25);
    }

    return 0;
}
