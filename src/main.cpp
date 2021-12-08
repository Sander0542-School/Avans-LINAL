#include "Engine/InputManager.hpp"
#include "Engine/Window.hpp"
#include "Models/Models.hpp"

#include "Entities/Entities.hpp"

#include <vector>

using namespace linal::engine;
using namespace linal::models;
using namespace linal::entities;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

const int SCALE = 30;

int main(int argc, char* args[])
{
    std::vector<std::shared_ptr<linal::entities::common::IDrawable>> drawables;

    Window window{"LINAL Assessment", 50, 50, WINDOW_WIDTH, WINDOW_HEIGHT};

    Point worldCenter{WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0};
    int worldScale = SCALE;

    auto block = std::make_shared<Block>();
    drawables.push_back(block);

    while (true)
    {
        if (!InputManager::GetInstance().Update()) break;

        window.Clear();

        // transform models

        for (const auto& drawable: drawables)
        {
            drawable->Draw(window, worldCenter, worldScale);
        }

        window.SwapBuffers();

        SDL_Delay(25);
    }

    return 0;
}
