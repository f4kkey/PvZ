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
        bool disapear();
        void biting(bool mask);
        virtual void render()=0;
        void move();
    protected:
        int health;
        int damage;
        int v;
        SDL_Rect pos;
        int row;
        bool live,exist;
        int preWalkTime,walkInterval;
        int preBiteTime,biteInterval;
        int deadTime;
        bool isBiting;
        int val;
        int legAngle,armAngle,vLeg,vArm;
        int vFall,bodyAngle;
        SDL_Point armCenter;
        SDL_Point bottom;
    private:


};
