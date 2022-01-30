#include <cstdio>
#include <SDL2/SDL.h>
#include "Breakout.hpp"
#include "MessageQueue.hpp"
#include "Framework.hpp"
#include "GameStateMachine.hpp"

extern MessageQueue gMessageQueue;
extern Framework gFramework;
extern GameStateMachine gGameStateMachine;

const Uint32 TICKS_PER_SECOND = 1000;
const Uint32 STEPS_PER_SECOND = 60;
const Uint32 TICKS_PER_STEP = TICKS_PER_SECOND / STEPS_PER_SECOND;

bool Breakout::startUp(int argc, char* argv[]) {
    if (argc > 0)
        printf("Arguments\n");
    
    for (int i = 0; i < argc; i++)
        printf("%s\n", argv[i]);
    
    if (gMessageQueue.startUp() == false) {
        return false;
    }

    if (gFramework.startUp() == false) {
        return false;
    }

    if (gGameStateMachine.startUp() == false) {
        return false;
    }

    return true;
}

void Breakout::shutDown() {
    gGameStateMachine.shutDown();
    gFramework.shutDown();
    gMessageQueue.shutDown();
}

void Breakout::mainLoop() {
    bool running = true;

    Uint32 elapsedTicks = 0;
    Uint32 pastTicks = SDL_GetTicks();

    while (running) {
        gFramework.processInput();

        while (gMessageQueue.isEmpty() == false) {
            Message message = gMessageQueue.popMessage();

            if (message.id == MESSAGE_QUIT) {
                running = false;
                break;
            }
        }

        Uint32 currentTicks = SDL_GetTicks();
        elapsedTicks += currentTicks - pastTicks;
        pastTicks = currentTicks;

        while (elapsedTicks >= TICKS_PER_STEP) {
            gGameStateMachine.updateStates();
            elapsedTicks -= TICKS_PER_STEP;
        }

        gFramework.beginRender();
        gGameStateMachine.renderStates();
        gFramework.renderTexture(TEXTURE_BALL, nullptr, nullptr);
        gFramework.endRender();
    }
}