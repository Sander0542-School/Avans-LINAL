#ifndef LINAL_ASSESSMENT_GAME_HPP
#define LINAL_ASSESSMENT_GAME_HPP

#include "Engine/Window.hpp"
#include "Engine/InputManager.hpp"

#include "Entities/Entities.hpp"
#include "Models/Models.hpp"


namespace linal
{

    class Game
    {
        private:
            const double WINDOW_WIDTH = 900;
            const double WINDOW_HEIGHT = 900;

            bool _quit = false;

            engine::Window _window = {"LINAL Assessment", {50, 50}, {WINDOW_WIDTH, WINDOW_HEIGHT}};
            models::Point _worldCenter = {WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0, 0};

        public:
            void Start();
            void Stop();
    };
}

#endif //LINAL_ASSESSMENT_GAME_HPP
