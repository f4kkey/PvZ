#pragma once
#include "all.h"
#include "plant.h"
#include "sun.h"
class sunFlower:public plant
{
    public:
        sunFlower();
        void render();
        void move();
    private:
        sun *s;
};
