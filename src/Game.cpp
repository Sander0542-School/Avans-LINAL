#include "Game.hpp"

using namespace linal;

void Game::Start()
{
    std::vector<std::shared_ptr<entities::common::IDrawable>> drawables;
    std::vector<std::shared_ptr<entities::common::IUpdatable>> updatables;

    auto entity = std::make_shared<entities::Spaceship>();
    drawables.push_back(entity);
    updatables.push_back(entity);

    while (!_quit)
    {
        if (!engine::InputManager::GetInstance().Update()) break;
        _window.Clear();

        // transform models

        for (const auto& updatable: updatables)
        {
            updatable->OnUpdate();
        }

        for (const auto& drawable: drawables)
        {
            drawable->Draw(_window, _worldCenter, SCALE);
        }

        _window.SwapBuffers();

        SDL_Delay(25);
    }
}

void Game::Stop()
{
    _quit = true;
}

