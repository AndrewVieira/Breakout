#include "Breakout.hpp"
#include "MessageQueue.hpp"
#include "Framework.hpp"
#include "GameStateMachine.hpp"

MessageQueue gMessageQueue;
Framework gFramework;
GameStateMachine gGameStateMachine;

int main(int argc, char* argv[]) {
    Breakout breakout;

    if (breakout.startUp(argc, argv) == true)
        breakout.mainLoop();
    
    breakout.shutDown();
    return 0;
}