#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

#include "Window.hpp"

using namespace linal::engine;
using namespace linal::models;

Window::Window(const std::string& title, int xpos, int ypos, int width, int height) : _window(nullptr, &SDL_DestroyWindow),
                                                                                      _renderer(nullptr, &SDL_DestroyRenderer),
                                                                                      _font(nullptr, &TTF_CloseFont),
                                                                                      _width(width),
                                                                                      _height(height)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    _window.reset(SDL_CreateWindow(title.c_str(), xpos, ypos, _width, _height, SDL_WINDOW_SHOWN));
    _renderer.reset(SDL_CreateRenderer(_window.get(), -1, 0));
    _font.reset(TTF_OpenFont("resources/arial.ttf", 18));

    SetDrawColor(Color::black());
}

void Window::RenderLine(const Point& point, const Vector& vector, const Color& color, const Point& offset)
{
    auto newPoint = CalculatePoint(offset, point);
    SetDrawColor(color);
    SDL_RenderDrawLine(_renderer.get(), newPoint.x, newPoint.y, newPoint.x + vector.x, newPoint.y + -vector.y);
}

void Window::RenderText(const std::string& text, const Point& point, const Color& color, const Point& offset)
{
    auto newPoint = CalculatePoint(offset, point);
    SDL_Color sdlColor{
            (Uint8) (color.R() * 255), (Uint8) (color.G() * 255), (Uint8) (color.B() * 255), (Uint8) (color.A() * 255)
    };
    SDL_Surface* surface = TTF_RenderText_Blended(_font.get(), text.c_str(), sdlColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), surface);

    SDL_Rect rect{(int) newPoint.x, (int) newPoint.y, surface->w, surface->h};

    SDL_RenderCopy(_renderer.get(), texture, nullptr, &rect);
}

void Window::RenderLine(int x1, int y1, int x2, int y2, const Color& color)
{
    SetDrawColor(color);
    SDL_RenderDrawLine(_renderer.get(), x1, y1, x2, y2);
}

Point Window::CalculatePoint(const Point& offset, Point point, bool invertY)
{
    if (invertY)
    {
        point.y = -point.y;
    }

    return offset + point;
}

void Window::SwapBuffers()
{
    SetDrawColor(Color::black());
    SDL_RenderPresent(_renderer.get());
}

void Window::Clear()
{
    SDL_RenderClear(_renderer.get());
}

void Window::SetDrawColor(Color color)
{
    SDL_SetRenderDrawBlendMode(_renderer.get(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(_renderer.get(), color.R() * 255, color.G() * 255, color.B() * 255, color.A() * 255);
}

#pragma clang diagnostic pop