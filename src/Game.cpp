#include "Game.hpp"
#include "Config.hpp"

using namespace linal;

void Game::Start()
{
    std::vector<std::shared_ptr<entities::common::IDrawable>> drawables;
    std::vector<std::shared_ptr<entities::common::IUpdatable>> updatables;

    auto camera = std::make_shared<entities::Camera>(models::Vector{0, 0, -50}, models::Vector{0,0,0});
    updatables.push_back(camera);

    auto entity = std::make_shared<entities::Spaceship>();
    drawables.push_back(entity);
    updatables.push_back(entity);

    while (!_quit)
    {
        if (!engine::InputManager::GetInstance().Update()) break;
        _window.Clear();

        if (engine::Input::GetKeyDown(engine::Input::KeyCode::H))
        {
            Config::Instance().DebugMode = !Config::Instance().DebugMode;
        }

        // transform models

        for (const auto& updatable: updatables)
        {
            updatable->OnUpdate();
        }

        for (const auto& drawable: drawables)
        {
            drawable->Draw(_window, camera);
        }

        _window.SwapBuffers();

        SDL_Delay(25);
    }
}

void Game::Stop()
{
    _quit = true;
}

