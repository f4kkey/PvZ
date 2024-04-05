#pragma once
#include "all.h"
class pea
{
    public:
        pea();
        void spawn(int x,int y);
        void move();
        void render();
        SDL_Rect getPos();
        int getDamage();
        bool alive();
    private:
        SDL_Rect pos;
        int v;
        int damage;
        bool live;
        int column,row;
};
