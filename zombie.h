#pragma once
#include "all.h"
class zombie
{
    public:
        zombie();
        SDL_Rect getPos();
        void spawn(int x=5);
        void takeDamage(int damageTaken);
        bool alive();
        int bite();
        void biting(bool mask);
        virtual void render()=0;
        virtual void move()=0;
    protected:
        int health;
        int damage;
        int v;
        SDL_Rect pos;
        int row;
        bool live;
        int walkTime,preWalkTime,walkSpeed;
        int biteTime,preBiteTime,biteSpeed;
        bool isBiting;
        int val;
    private:


};
