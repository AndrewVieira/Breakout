#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <SDL2/SDL.h>
#include "Assets/Texture.hpp"

enum TextureId {
    TEXTURE_BALL,
    TEXTURE_BLOCK,
    TEXTURE_PADDLE,
    TOTAL_TEXTURES
};

class Framework {
    public:
        bool startUp();
        void shutDown();

        void processInput();
        void beginRender();
        void endRender();

        void renderTexture(TextureId id, const SDL_Rect* dst, const SDL_Rect* clip=nullptr);

        SDL_Renderer* getRenderer();
    
    private:
        SDL_Window* mWindow = nullptr;
        SDL_Renderer* mRenderer = nullptr;

        Texture mTextures[TOTAL_TEXTURES];
};

#endif // FRAMEWORK_HPP
