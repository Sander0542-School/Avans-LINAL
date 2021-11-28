#include "InputManager.hpp"

#include <algorithm>

using namespace linal::engine;
using namespace linal::models;

InputManager InputManager::_instance{};

InputManager::InputManager() : _mousePosition{new Point()}, _mousePrevious{0}, _mouseCurrent{0}
{
}

bool InputManager::AnyKeyDown()
{
    for (int i = 0; i < _keysCurrent.size(); ++i)
        if (_keysCurrent[i] == 1 && _keysPrevious[i] == 0) return true;
    return false;
}

bool InputManager::AnyKey() const
{
    for (auto key: _keysCurrent)
        if (key == 1) return true;
    return false;
}

bool InputManager::KeyDown(const Input::KeyCode& keyCode)
{
    auto key = ToKey(keyCode);
    if (_keysPrevious.empty()) return _keysCurrent[key] == 1;
    return _keysPrevious[key] == 1 && _keysCurrent[key] == 1;
}

bool InputManager::KeyFrameDown(const Input::KeyCode& keyCode)
{
    auto key = ToKey(keyCode);
    if (_keysPrevious.empty()) return _keysCurrent[key] == 1;
    return _keysPrevious[key] == 0 && _keysCurrent[key] == 1;
}

bool InputManager::KeyFrameUp(const Input::KeyCode& keyCode)
{
    auto key = ToKey(keyCode);
    if (_keysPrevious.empty()) return false;
    return _keysPrevious[key] == 1 && _keysCurrent[key] == 0;
}

bool InputManager::MouseDown(const Input::MouseButton& mouseButton) const
{
    auto mouse = ToKey(mouseButton);
    if (_mousePrevious == 0) return (_mouseCurrent & mouse) != 0;
    return (_mousePrevious & mouse) != 0 && (_mouseCurrent & mouse) != 0;
}

bool InputManager::MouseFrameDown(const Input::MouseButton& mouseButton) const
{
    auto mouse = ToKey(mouseButton);
    if (_mousePrevious == 0) return (_mouseCurrent & mouse) != 0;
    return (_mousePrevious & mouse) == 0 && (_mouseCurrent & mouse) != 0;
}

bool InputManager::MouseFrameUp(const Input::MouseButton& mouseButton) const
{
    auto mouse = ToKey(mouseButton);
    if (_mousePrevious == 0) return false;
    return (_mousePrevious & mouse) != 0 && (_mouseCurrent & mouse) == 0;
}

const Point& InputManager::MousePosition() const
{
    return *_mousePosition;
}

bool InputManager::Update()
{
    SDL_Event event{};
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) return false;
    }

    SDL_PumpEvents();

    int x, y;
    _mousePrevious = _mouseCurrent;
    _mouseCurrent = SDL_GetMouseState(&x, &y);

    _mousePosition->x = x;
    _mousePosition->y = y;

    _keysPrevious = std::move(_keysCurrent);
    int length = 0;
    const unsigned char* keysBuffer = SDL_GetKeyboardState(&length);

    _keysCurrent = {keysBuffer, keysBuffer + length};

    return true;
}

InputManager& InputManager::GetInstance()
{
    return _instance;
}

Uint8 InputManager::ToKey(const Input::MouseButton& mouseButton)
{
    switch (mouseButton)
    {
        case Input::MouseButton::LEFT:
            return SDL_BUTTON_LEFT;
        case Input::MouseButton::MIDDLE:
            return SDL_BUTTON_MIDDLE;
        case Input::MouseButton::RIGHT:
            return SDL_BUTTON_RIGHT;
    }
    return 0;
}

unsigned char InputManager::ToKey(const Input::KeyCode& key)
{
    return static_cast<char>(key);
}