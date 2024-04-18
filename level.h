#pragma once
#include "all.h"
class levelMenu
{
    public:
        levelMenu();
        void render();
        void event(SDL_Event e);
        int getVal();
    private:
        bool join;
        SDL_Rect level1,level2,quit;
        int val;
};
