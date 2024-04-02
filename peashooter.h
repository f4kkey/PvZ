#pragma once
#include "all.h"
#include "pea.h"
class peashooter
{
    public:
        peashooter();
        void render();
        void spawn(int &x,int &y);
        bool fire();
        SDL_Rect getPos();
    private:
        double health;
        int fireRate;
        SDL_Rect pos;
        int fireTime,preFireTime;
};
