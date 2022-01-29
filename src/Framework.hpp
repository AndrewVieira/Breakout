#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <SDL2/SDL.h>

class Framework {
    public:
        bool startUp();
        void shutDown();

        void processInput();
        void beginRender();
        void endRender();
    
    private:
        SDL_Window* mWindow = nullptr;
        SDL_Renderer* mRenderer = nullptr;
};

#endif // FRAMEWORK_HPP
