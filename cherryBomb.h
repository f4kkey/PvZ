#pragma once
#include "all.h"
#include "plant.h"
class cherryBomb:public plant
{
    public:
        cherryBomb();
        void render();
        void move();
        void preRender();
    private:
        SDL_Rect radius;
        int explodeTime;
        SDL_Rect sprite[2];
};
