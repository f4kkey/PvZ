#pragma once
#include "all.h"
#include "plant.h"
class wallnut:public plant
{
    public:
        wallnut();
        void render();
        void move();
        void preRender();
    private:
        SDL_Rect sprite[3];
};
