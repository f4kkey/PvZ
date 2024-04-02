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
        void takeDamage(int damageTaken);
        bool alive();
    private:
        int health;
        bool live;
        int fireSpeed;
        SDL_Rect pos;
        int fireTime,preFireTime;
};
