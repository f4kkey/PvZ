#pragma once
#include "all.h"
#include "sun.h"
#include "plant.h"
#include "peashooter.h"
#include "sunFlower.h"
#include "wallnut.h"
#include "cherryBomb.h"
#include "potatoMine.h"
#include "repeater.h"
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
        static vector<sun*> s;
    private:
        int sunSpawnTime,preSunSpawnTime,sunSpawnSpeed;
        SDL_Rect seedPos[8];
        SDL_Rect seedPricePos[8];
        SDL_Rect pos;
        int totalSun;

        sun* S;
        int pickVal;
        plant* cursor;
        peashooter* ps;
        sunFlower* sf;
        wallnut* wn;
        cherryBomb* cb;
        potatoMine* pm;
        repeater* rp;
        SDL_Texture *price;
        int textWidth,textHeight;
};
