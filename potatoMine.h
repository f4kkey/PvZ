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
        void preRender();
    private:
        SDL_Rect sprite[2];
        SDL_Rect radius;
        int v;
        int explosionTime;
};
