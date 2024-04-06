#pragma once
#include "all.h"
#include "zombie.h"
class coneZombie:public zombie
{
    public:
        coneZombie();
        void render();
        void move();
    private:
};
