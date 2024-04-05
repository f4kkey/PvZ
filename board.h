#pragma once
#include "all.h"
#include "basicZombie.h"
#include "pea.h"
#include "peashooter.h"
#include "shop.h"
#include "lawnmover.h"
using namespace std;
class board
{
    public:
        board();
        void loadTexture(const char* s);
        void start();
        void event(SDL_Event e);
        void update();
        void render();
        bool detechZombie(int &row,SDL_Rect position);
        void spawnSun();
        void spawn(plant* tmpPlant);
        static SDL_Rect pos[9][5];
        static bool exist[9][5];
        static vector<zombie*> z[5];
        static vector<pea*> pe[5];
        static vector<plant*> p[5];
    private:
        lawnmover* l[5];
        SDL_Texture* tex;
        shop s;
        basicZombie* Z1;
        pea* PE;
        peashooter* P;


};
