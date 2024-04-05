#pragma once
#include "all.h"
#include "plant.h"
class shovel:public plant
{
    public:
        shovel();
        void render();
        void move();
};
