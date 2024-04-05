#pragma once
#include "all.h"
#include "sun.h"
#include "plant.h"
class shop
{
    public:
        shop();
        void spawn();
        void event(SDL_Event e);
        void update();
        void render();
        void placePeaShooter(int column,int row);

    private:
        int sunSpawnTime,preSunSpawnTime,sunSpawnSpeed;
        SDL_Rect seedPos[7];
        SDL_Rect pos;
        int totalSun;
        vector<sun*> s;
        sun* S;
        int pickVal;
        bool picked;
        plant* cursor;

};
