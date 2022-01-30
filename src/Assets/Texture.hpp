#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
#include <SDL2/SDL.h>
#include "Asset.hpp"

class Texture : public Asset {
    public:
        ~Texture();

        bool loadFromPath(std::string path);
        void free();

        void setColor(Uint8 red, Uint8 green, Uint8 blue);
        void setBlendMode(SDL_BlendMode blending);
        void setAlpha(Uint8 alpha);
        void render(const SDL_Rect* dst, const SDL_Rect* clip=nullptr);

        int getWidth();
        int getHeight();

    private:
        SDL_Texture* mTexture = nullptr;
        int mWidth = 0;
        int mHeight = 0;
};

#endif // TEXTURE_HPP