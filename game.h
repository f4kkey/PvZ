#pragma once
#include "all.h"
#include "board.h"
#include "level.h"
class game
{
    public:
        game();
        void init();
        void loadResources();
        void event();
        bool getGameState();
        void render();

    private:
        int time,pretime;
        bool restart;
        bool gameState;
        SDL_Event e;
        board b;
        levelMenu lv;
        int ingame;
};
