#pragma once
#include "all.h"
#include "plant.h"
class cherryBomb:public plant
{
    public:
        cherryBomb();
        void render();
        void move();
        void spawn(int i,int j);
    private:
        SDL_Rect radius;
};
