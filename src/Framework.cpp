#include <cstdio>
#include <SDL2/SDL_image.h>
#include "MessageQueue.hpp"
#include "Framework.hpp"

extern MessageQueue gMessageQueue;

bool Framework::startUp() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    if (mWindow == nullptr) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (mRenderer == nullptr) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    mTextures[TEXTURE_BALL].loadFromPath("../assets/Textures/Ball.png");
    mTextures[TEXTURE_BLOCK].loadFromPath("../assets/Textures/Block.png");
    mTextures[TEXTURE_PADDLE].loadFromPath("../assets/Textures/Paddle.png");

    return true;
}

void Framework::shutDown() {
    for (int i = 0; i < TOTAL_TEXTURES; i++)
        mTextures[i].free();

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
}

void Framework::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_QUIT: gMessageQueue.pushMessage(MESSAGE_QUIT); break;
            default: break;
        }
    }
}

void Framework::beginRender() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
}

void Framework::endRender() {
    SDL_RenderPresent(mRenderer);
}

SDL_Renderer* Framework::getRenderer() {
    return mRenderer;
}

void Framework::renderTexture(TextureId id, const SDL_Rect* dst, const SDL_Rect* clip) {
    if (id == TOTAL_TEXTURES) { return; }
    mTextures[id].render(dst, clip);
}