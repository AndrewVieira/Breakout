#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "GameState.hpp"
#include "../GameObjects/Button.hpp"
#include "../GameObjects/Image.hpp"
#include "../GameObjects/Text.hpp"

class MenuState : public GameState {
    public:
        void onEnter();
        void onExit();

        void update();
        void render();
    
    private:

};

#endif // MENU_STATE_HPP
