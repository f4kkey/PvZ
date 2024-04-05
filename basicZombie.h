#pragma once
#include "all.h"
#include "zombie.h"
class basicZombie:public zombie
{
    public:
        basicZombie();
        void render();
        void move();
    private:
};
