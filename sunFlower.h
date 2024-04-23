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
        void spawn(int i,int j);
    private:
        sun *s;
};
