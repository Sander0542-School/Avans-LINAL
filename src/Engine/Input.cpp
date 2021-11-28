#include "Input.hpp"
#include "InputManager.hpp"

using namespace linal::engine;
using namespace linal::models;

bool Input::AnyKey()
{
    return InputManager::GetInstance().AnyKey();
}

bool Input::AnyKeyDown()
{
    return InputManager::GetInstance().AnyKeyDown();
}

const Point Input::MousePosition()
{
    return InputManager::GetInstance().MousePosition();
}

bool Input::GetKey(KeyCode key)
{
    return InputManager::GetInstance().KeyDown(key);
}

bool Input::GetKeyDown(KeyCode key)
{
    return InputManager::GetInstance().KeyFrameDown(key);
}

bool Input::GetKeyUp(KeyCode key)
{
    return InputManager::GetInstance().KeyFrameUp(key);
}

bool Input::GetMouseButton(MouseButton which)
{
    return InputManager::GetInstance().MouseDown(which);
}

bool Input::GetMouseButtonDown(MouseButton which)
{
    return InputManager::GetInstance().MouseFrameDown(which);
}

bool Input::GetMouseButtonUp(MouseButton which)
{
    return InputManager::GetInstance().MouseFrameUp(which);
}