#include <cstdio>
#include <SDL2/SDL_image.h>
#include "../Framework.hpp"
#include "Texture.hpp"

extern Framework gFramework;

Texture::~Texture(){
    free();
}

bool Texture::loadFromPath(std::string path) {
    free();

    SDL_Texture* texture = nullptr;

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        return false;
    }

    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 255));
    texture = SDL_CreateTextureFromSurface(gFramework.getRenderer(), surface);

    if (texture == nullptr) {
        printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        return false;
    }

    mWidth = surface->w;
    mHeight = surface->h;

    SDL_FreeSurface(surface);

    mTexture = texture;
    return true;
}

void Texture::free() {
    if (mTexture == nullptr) { return; }

    SDL_DestroyTexture(mTexture);
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending) {
    SDL_SetTextureBlendMode(mTexture, blending);
}

void Texture::setAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Texture::render(const SDL_Rect* dst, const SDL_Rect* clip) {
    SDL_Rect renderQuad = {};
    if (dst != nullptr) {
        renderQuad = { dst->x, dst->y, dst->w, dst->h };
    }

    if (renderQuad.w == 0)
        renderQuad.w = mWidth;
    
    if (renderQuad.h == 0)
        renderQuad.h = mHeight;

    SDL_RenderCopy(gFramework.getRenderer(), mTexture, clip, &renderQuad);
}

int Texture::getWidth() {
    return mWidth;
}

int Texture::getHeight() {
    return mHeight;
}