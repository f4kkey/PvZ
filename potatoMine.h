#pragma once
#include "all.h"
#include "plant.h"
class potatoMine:public plant
{
    public:
        potatoMine();
        void render();
        void move();
    private:
        SDL_Rect radius;
        int v;
};
