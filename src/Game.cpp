#include "Game.hpp"

using namespace linal;

void Game::Start()
{
    std::vector<std::shared_ptr<entities::common::IDrawable>> drawables;
    auto entity = std::make_shared<entities::Block>();
    drawables.push_back(entity);

    while (!_quit)
    {
        if (!engine::InputManager::GetInstance().Update()) break;
        _window.Clear();

        // transform models

        for (const auto& drawable: drawables)
        {
            drawable->Draw(_window);
        }

        _window.SwapBuffers();

        SDL_Delay(25);
    }
}

void Game::Stop()
{
    _quit = true;
}

