#pragma once
#include<bits/stdc++.h>
#include<SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
using namespace std;

const int SCREEN_WIDTH=1200;
const int SCREEN_HEIGHT=800;
const int TILE_WIDTH=120;
const int TILE_HEIGHT=100;
const int PLANT_WIDTH=100;
const int PLANT_HEIGHT=100;

SDL_Texture* loadIMG(const char* s);
bool inside(int x,int y,SDL_Rect rect);
extern SDL_Window* window;
extern SDL_Renderer* ren;

extern SDL_Texture *tPea;
extern SDL_Texture *tSun;
extern SDL_Texture *tShovel;
extern SDL_Texture *tLawnmover;
extern SDL_Texture *tBlank;
extern SDL_Texture *tFinalWave;
extern SDL_Texture *tLevel;
extern SDL_Texture *tLose;
extern SDL_Texture *tWin;
extern int mousePosX,mousePosY;
extern TTF_Font *font;

extern SDL_Texture *tPlant[6];
extern SDL_Texture *tPlant2[6];

extern SDL_Texture *tHead;
extern SDL_Texture *tBody;
extern SDL_Texture *tBackArm;
extern SDL_Texture *tBackFlagArm;
extern SDL_Texture *tFrontArm;
extern SDL_Texture *tBackLeg;
extern SDL_Texture *tFrontLeg;
extern SDL_Texture *tCone;
extern SDL_Texture *tCone2;
extern SDL_Texture *tCone3;
extern SDL_Texture *tBucket;
extern SDL_Texture *tBucket2;
extern SDL_Texture *tBucket3;

extern Mix_Chunk *mEat;
extern Mix_Chunk *mSwallow;
extern Mix_Chunk *mSplat;
extern Mix_Chunk *mPlant;
extern Mix_Chunk *mSun;
extern Mix_Chunk *mPotatoMine;
extern Mix_Chunk *mCherryBomb;
extern Mix_Chunk *mFirstWave;
extern Mix_Chunk *mSeedPacket;
extern Mix_Chunk *mWave;
extern Mix_Music *mInGame;
extern Mix_Music *mMenu;
extern Mix_Music *mWin;
extern Mix_Music *mLose;

bool collision(SDL_Rect A,SDL_Rect B);


