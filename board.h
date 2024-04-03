#pragma once
#include "all.h"
#include "basicZombie.h"
#include "pea.h"
#include "peashooter.h"
#include "shop.h"
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
        bool collision(SDL_Rect A,SDL_Rect B);
        bool detechZombie(int &row,SDL_Rect position);
        void spawn();
    private:
        SDL_Texture* tex;
        SDL_Point pos[9][5];
        shop s;
        vector<basicZombie> z1[5];
        basicZombie Z1;
        vector<pea> pe[5];
        pea PE;
        vector<peashooter> p[5];
        peashooter P;
};
