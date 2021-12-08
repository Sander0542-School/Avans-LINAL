#ifndef LINAL_ASSESSMENT_WINDOW_HPP
#define LINAL_ASSESSMENT_WINDOW_HPP

#include <SDL.h>
#include <SDL_ttf.h>

#include "Color.hpp"
#include "Enums/WindowView.hpp"
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
            enums::WindowView _windowView;

            int _width;
            int _height;

        public:
            Window(const std::string& title, int xpos, int ypos, int width, int height, enums::WindowView windowView = enums::WindowView::Front);

            void RenderLine(const models::Point& point, const models::Vector& vector, const Color& color, const models::Point& offset = {});

            void RenderLine(int x1, int y1, int x2, int y2, const Color& color);

            void RenderText(const std::string& text, const models::Point& point, const Color& color, const models::Point& offset = {});

            models::Point CalculatePoint(const models::Point& offset, models::Point point, bool invertY = true);

            void SetDrawColor(Color color);

            void SwapBuffers();

            void Clear();

            [[nodiscard]] int Width() const
            {
                return _width;
            }

            [[nodiscard]] int Height() const
            {
                return _height;
            }
    };
}

#endif //LINAL_ASSESSMENT_WINDOW_HPP
