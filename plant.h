#pragma once
#include "all.h"
class plant
{
    public:
        plant();
        virtual void render()=0;
        virtual void move()=0;
        void spawn(int x,int y);
        bool fire();
        SDL_Rect getPos();
        void takeDamage(int damageTaken);
        bool alive();
        bool isPicked();
        void changePickState();
        void setPos(int x,int y);
        int getColumn();
        int getRow();
        int getPrice();
    protected:
        int health;
        bool live;
        int fireSpeed;
        SDL_Rect pos;
        int column,row;
        int fireTime,preFireTime;
        bool picked;
        int price;
        int rechargeSpeed;
        int damage;
        SDL_Rect sprite;

    private:

};
