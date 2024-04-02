#pragma once
#include "all.h"
#include "basicZombie.h"
#include "pea.h"
#include "peashooter.h"
using namespace std;
class board
{
    public:
        board();
        void loadTexture(const char* s);
        void start();
        void update();
        void render();
        bool collision(SDL_Rect A,SDL_Rect B);
        bool detechZombie(int &row,SDL_Rect position);
    private:
        SDL_Texture* tex;
        SDL_Point pos[9][5];
        vector<basicZombie> z1[5];
        basicZombie Z1;
        vector<pea> pe[5];
        pea PE;
        vector<peashooter> p[5];
        peashooter P;
};
