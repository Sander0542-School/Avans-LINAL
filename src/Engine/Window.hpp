#ifndef LINAL_ASSESSMENT_WINDOW_HPP
#define LINAL_ASSESSMENT_WINDOW_HPP

#include <SDL.h>
#include <SDL_ttf.h>

#include "Color.hpp"
#include "Models/Models.hpp"

#include <memory>
#include <string>

namespace linal::engine
{
    class Window
    {
        private:
            std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
            std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer;
            std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> _font;

            models::Point _size;
            models::Point _center;

        public:
            Window(const std::string& title, models::Point position, models::Point size);

            void RenderLine(double x1, double y1, double x2, double y2);

            void RenderText(const std::string& text, const models::Point& point, const Color& color, const models::Point& offset = {});

            models::Point CalculatePoint(const models::Point& offset, models::Point point, bool invertY = true);

            void SetDrawColor(Color color);

            void SwapBuffers();

            void Clear();

            [[nodiscard]] models::Point Size() const
            {
                return _size;
            }

            [[nodiscard]] int Width() const
            {
                return _size.x;
            }

            [[nodiscard]] int Height() const
            {
                return _size.y;
            }
    };
}

#endif //LINAL_ASSESSMENT_WINDOW_HPP
