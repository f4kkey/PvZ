#pragma once
#include "all.h"
class sun
{
    public:
        sun();
        void spawn(int x=-1,int y=-1,int range=-1);
        void setEndPos(int y);
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
