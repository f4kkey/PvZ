#pragma once
#include "all.h"
#include "plant.h"
class cherryBomb:public plant
{
    public:
        cherryBomb();
        void render();
        void move();
    private:
        SDL_Rect radius;
};
