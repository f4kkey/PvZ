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
    private:
        pea *bullet;
        int tmpFireInterval[2];
        int type;
};
