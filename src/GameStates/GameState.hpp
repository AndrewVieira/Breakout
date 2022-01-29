#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

enum GameStateId {
    GAME_STATE_MENU,
    GAME_STATE_PLAY,
    GAME_STATE_PAUSE,
    GAME_STATE_OPTIONS,
    GAME_STATE_TOTAL
};

enum TransitionType {
    TRANSITION_NONE,
    TRANSITION_PUSH,
    TRANSITION_POP,
    TRANSITION_CHANGE
};

struct Transition {
    GameStateId id = GAME_STATE_TOTAL;
    TransitionType type = TRANSITION_NONE;
};

class GameState {
    public:
        virtual ~GameState() {}
        virtual void onEnter() = 0;
        virtual void onExit() = 0;

        virtual void update() = 0;
        virtual void render() = 0;

        Transition getTransition() { 
            Transition transition = mTransition;
            mTransition = {};
            return transition; 
        }
    
    protected:
        Transition mTransition = {};
};

#endif // GAME_STATE_HPP