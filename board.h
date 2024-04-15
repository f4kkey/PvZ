#pragma once
#include "all.h"
#include "zombie.h"
#include "basicZombie.h"
#include "coneZombie.h"
#include "pea.h"
#include "plant.h"
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
        void levelProgess(int num);
        void update();
        void render();
        bool checkEmpty();
        void spawn(int num);
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
        coneZombie* Z2;
        pea* PE;
        ifstream levelFile;
        vector<int> level[5];
        int preWave;
        int curWave;
        bool finalWave;
        int finalWaveStartTime;
        SDL_Rect finalWaveRect;

};
