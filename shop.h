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
#include "shovel.h"
class shop
{
    public:
        shop();
        void reset();
        void spawn();
        void event(SDL_Event e);
        void update();
        void render();
        void placePlant(int column,int row,int val);
        void renderText(int v,int i);
        static vector<sun*> s;
    private:
        int sunSpawnTime,preSunSpawnTime,sunSpawnSpeed;
        SDL_Rect seedPos[8];
        SDL_Rect seedPricePos[8];
        int totalSun;
        vector<plant*> p;
        sun* S;
        int pickVal;
        plant* cursor;
        SDL_Texture *priceText;
        int textWidth,textHeight;
};
