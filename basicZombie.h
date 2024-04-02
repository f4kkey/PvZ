#pragma once
#include "all.h"
class basicZombie
{
    public:
        basicZombie();
        void move();
        void render();
        void spawn(int x=5);
        SDL_Rect getPos();
        void takeDamage(int damageTaken);
        bool alive();
        int bite();
        void biting(bool mask);
    private:
        int health,damage;
        double v;
        SDL_Rect pos;
        int lane;
        bool live;
        int walkTime,preWalkTime,walkSpeed;
        int biteTime,preBiteTime,biteSpeed;
        bool isBiting;
};
