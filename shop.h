#pragma once
#include "all.h"
#include "sun.h"
#include "plant.h"
#include "peashooter.h"
class shop
{
    public:
        shop();
        void spawn();
        void event(SDL_Event e);
        void update();
        void render();
        void placePlant(int column,int row);
        void renderText(int v,int i);

    private:
        int sunSpawnTime,preSunSpawnTime,sunSpawnSpeed;
        SDL_Rect seedPos[8];
        SDL_Rect seedPricePos[8];
        SDL_Rect pos;
        int totalSun;
        vector<sun*> s;
        sun* S;
        int pickVal;
        plant* cursor;
        peashooter* p1;
        SDL_Texture *price;
        int textWidth,textHeight;
};
