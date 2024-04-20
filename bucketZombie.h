#pragma once
#include "all.h"
#include "zombie.h"
class bucketZombie:public zombie
{
    public:
        bucketZombie();
        void render();
        void move();
    private:
};
