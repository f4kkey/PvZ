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
const int lanePos[5]={350,450,550,650,750};
SDL_Texture* loadIMG(const char* s);
bool inside(int x,int y,SDL_Rect rect);
extern SDL_Window* window;
extern SDL_Renderer* ren;
extern SDL_Texture *tPea;
extern SDL_Texture *tBasicZombie;
extern SDL_Texture *tPeashooter;
extern SDL_Texture *tSun;
extern SDL_Texture *tShovel;
extern SDL_Texture *tLawnmover;
extern SDL_Texture *tSunFlower;
extern SDL_Texture *tWallnut;
extern int mousePosX,mousePosY;
extern TTF_Font *font;
bool collision(SDL_Rect A,SDL_Rect B);


