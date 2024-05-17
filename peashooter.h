#pragma once
#include "all.h"
#include "pea.h"
#include "plant.h"
class peashooter:public plant
{
    public:
        peashooter();
        void render();
        void move();

    private:
        pea *bullet;
};
