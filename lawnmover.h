#pragma once
#include "all.h"
class lawnmover
{
    public:
        lawnmover();
        void move();
        void render();
        void reset(int i);
    private:
        SDL_Rect pos;
        bool used;
        int row,column;
        int v;
};
