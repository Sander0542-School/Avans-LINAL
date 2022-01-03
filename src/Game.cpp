#include "Game.hpp"

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

    auto target = std::make_shared<entities::CelestialBody>();

    target->Transform(models::Matrix::Translation(0, 0, 18));
    target->Transform(models::Matrix::Pitch(12.5));
    target->Transform(models::Matrix::Roll(7.5));
    target->Transform(models::Matrix::Yaw(4.5));
    drawables.push_back(target);
    updatables.push_back(target);

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

