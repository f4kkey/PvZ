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
        bool alive();
    private:
        int value,fallSpeed;
        SDL_Rect pos;

        int endPos;
        int endTime,duration,curTime;
        int live;
};
