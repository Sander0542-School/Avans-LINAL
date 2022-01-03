#include "Texture.hpp"

using namespace linal::engine;

void DestructTexture(SDL_Texture* tex)
{
    SDL_DestroyTexture(tex);
}

Texture::Texture(SDL_Surface* surface, SDL_Texture* texture) : _surface(surface, &SDL_FreeSurface),
                                                               _texture(texture, &DestructTexture)
{
    SDL_QueryTexture(texture, nullptr, nullptr, &_width, &_height);
}

SDL_Texture* Texture::Get() const
{
    return _texture.get();
}

SDL_Surface* Texture::Surface() const
{
    return _surface.get();
}

const int& Texture::Width() const
{
    return _width;
}

const int& Texture::Height() const
{
    return _height;
}