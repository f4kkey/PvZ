#pragma once
#include "all.h"
class plant
{
    public:
        plant();
        virtual void render();
        virtual void move();
        virtual void spawn(int i,int j);
        virtual void preRender();
        SDL_Rect getPos();
        void takeDamage(int damageTaken);
        bool alive();
        void setPos(int x,int y);
        int getColumn();
        int getRow();
        int getPrice();
        bool plantable();
        void setPlantTime(int x);
    protected:

        int health;
        bool live;
        int fireInterval;
        SDL_Rect pos;
        int column,row;
        int preFireTime;
        int prePlantTime;
        int price;
        int recharge;
        int damage;
        int value;
        SDL_Rect rechargeRect;


    private:

};
