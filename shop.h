#pragma once
#include "all.h"
#include "sun.h"
class shop
{
    public:
        shop();
        void spawn();
        void event(SDL_Event e);
        void update();
        void render();

    private:
        SDL_Rect pos;
        int totalSun;
        vector<sun> s;
        sun S;

};
