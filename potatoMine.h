#pragma once
#include "all.h"
#include "plant.h"
class potatoMine:public plant
{
    public:
        potatoMine();
        void render();
        void move();
        void spawn(int i,int j);
    private:
        SDL_Rect sprite;
        SDL_Rect radius;
        int v;
};
