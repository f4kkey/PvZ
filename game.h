#pragma once
#include<bits/stdc++.h>
#include "all.h"
#include "board.h"
class game
{
    public:
        game();
        void init();
        void loadResources();
        void event();
        bool getGameState();
        void render();
        void setup();

    private:
        int time,pretime;
        bool pause;
        bool gameState;
        SDL_Event e;
        board b;
};
