#pragma once
#include "all.h"
#include "pea.h"
#include "plant.h"
class repeater:public plant
{
    public:
        repeater();
        void render();
        void move();
        void spawn(int i,int j);
    private:
        pea *bullet;
        int tmpFireInterval[2];
        int type;
};
