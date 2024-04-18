#pragma once
#include<bits/stdc++.h>
#include<SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
using namespace std;

const int SCREEN_HEIGHT=800;
const int SCREEN_WIDTH=1200;
const int TILE_HEIGHT=100;
const int TILE_WIDTH=120;
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
extern SDL_Texture *tLevel1;

extern SDL_Texture *tPeashooter;
extern SDL_Texture *tSunFlower;
extern SDL_Texture *tWallnut;
extern SDL_Texture *tCherryBomb;
extern SDL_Texture *tPotatoMine;
extern SDL_Texture *tRepeater;

extern SDL_Texture *tBody;
extern SDL_Texture *tBackHand;
extern SDL_Texture *tFrontHand;
extern SDL_Texture *tBackLeg;
extern SDL_Texture *tFrontLeg;
extern SDL_Texture *tCone;
extern SDL_Texture *tBucket;
extern int mousePosX,mousePosY;
extern TTF_Font *font;
bool collision(SDL_Rect A,SDL_Rect B);


