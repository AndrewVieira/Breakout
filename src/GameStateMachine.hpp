#ifndef GAME_STATE_MACHINE_HPP
#define GAME_STATE_MACHINE_HPP

#include "MessageQueue.hpp"
#include "GameStates/GameState.hpp"

class GameStateMachine {
    public:
        bool startUp();
        void shutDown();

        void handleMessage(Message message);
        void updateStates();
        void renderStates();
    
    private:
        void pushState(GameStateId id);
        void popState();
        void changeState(GameStateId id);
};

#endif // GAME_STATE_MACHINE_HPP
