#ifndef LINAL_ASSESSMENT_INPUTMANAGER_HPP
#define LINAL_ASSESSMENT_INPUTMANAGER_HPP

#include "Input.hpp"
#include "Models/Point.hpp"

#include "SDL.h"

#include <map>
#include <memory>
#include <vector>

namespace linal::engine
{
    class InputManager
    {
        private:
            std::vector<unsigned char> _keysCurrent = {};
            std::vector<unsigned char> _keysPrevious = {};
            Uint32 _mouseCurrent = 0;
            Uint32 _mousePrevious = 0;
            std::unique_ptr<models::Point> _mousePosition = {};
            static InputManager _instance;
        public:
            InputManager();

            bool AnyKeyDown();

            [[nodiscard]] bool AnyKey() const;

            bool KeyDown(const Input::KeyCode& keyCode);

            bool KeyFrameDown(const Input::KeyCode& keyCode);

            bool KeyFrameUp(const Input::KeyCode& keyCode);

            [[nodiscard]] bool MouseDown(const Input::MouseButton& button) const;

            [[nodiscard]] bool MouseFrameDown(const Input::MouseButton& button) const;

            [[nodiscard]] bool MouseFrameUp(const Input::MouseButton& button) const;

            [[nodiscard]] const models::Point& MousePosition() const;

            bool Update();

            static InputManager& GetInstance();

            static unsigned char ToKey(const Input::KeyCode& key);

            static Uint8 ToKey(const Input::MouseButton& button);
    };
}

#endif //LINAL_ASSESSMENT_INPUTMANAGER_HPP
