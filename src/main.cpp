#include "Engine/InputManager.hpp"
#include "Engine/Window.hpp"
#include "Models/Models.hpp"

#include "Entities/Entities.hpp"

#include <vector>

using namespace linal::engine;
using namespace linal::models;
using namespace linal::entities;
using namespace linal::enums;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 450;

const int SCALE = 25;

int main(int argc, char* args[])
{
    std::vector<Window> windows;
    windows.emplace_back("LINAL Assessment - Front", 10, 50, WINDOW_WIDTH, WINDOW_HEIGHT, WindowView::Front);
    windows.emplace_back("LINAL Assessment - Top", 10, WINDOW_HEIGHT + 100, WINDOW_WIDTH, WINDOW_HEIGHT, WindowView::Top);
    windows.emplace_back("LINAL Assessment - Side", WINDOW_WIDTH + 20, WINDOW_HEIGHT + 100, WINDOW_WIDTH, WINDOW_HEIGHT, WindowView::Side);

    Point worldCenter{WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0};
    int worldScale = SCALE;

    std::vector<std::shared_ptr<linal::entities::common::IDrawable>> drawables;
    auto entity = std::make_shared<Spaceship>();
    drawables.push_back(entity);

    while (true)
    {
        if (!InputManager::GetInstance().Update()) break;

        for (auto& window: windows) window.Clear();

        // transform models

        for (const auto& drawable: drawables)
        {
            for (auto& window: windows)
                drawable->Draw(window, worldCenter, worldScale);
        }

        for (auto& window: windows) window.SwapBuffers();

        SDL_Delay(25);
    }

    return 0;
}
