#pragma once
#include "all.h"
class sun
{
    public:
        sun();
        bool spawn();
        SDL_Rect getPos();
        void move();
        void render();
        int event(SDL_Event e);
    private:
        int value,fallSpeed;
        SDL_Rect pos;
        int sunSpawnTime,preSunSpawnTime,sunSpawnSpeed;
        int endPos;
};
