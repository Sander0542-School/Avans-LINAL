#include "Engine/InputManager.hpp"
#include "Engine/Window.hpp"
#include "Models/Models.hpp"

using namespace linal::engine;
using namespace linal::models;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

int main(int argc, char* args[])
{
    Window window{"LINAL Assessment", 50, 50, WINDOW_WIDTH, WINDOW_HEIGHT};

//    Point worldCenter{WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0};

    while (true)
    {
        if (!InputManager::GetInstance().Update()) break;

        window.Clear();

        // transform models

        // draw models

        window.SwapBuffers();

        SDL_Delay(25);
    }

    return 0;
}
