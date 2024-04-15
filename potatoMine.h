#pragma once
#include "all.h"
#include "plant.h"
class potatoMine:public plant
{
    public:
        potatoMine();
        void render();
        void move();
        void fixedSprite();
    private:
        SDL_Rect radius;
        int v;
};
