#pragma once
#include "all.h"
class lawnmover
{
    public:
        lawnmover();
        void move();
        void setRow(int i);
        void render();
    private:
        SDL_Rect pos;
        bool used;
        int row,column;
        int v;
};
