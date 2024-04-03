#include "all.h"
SDL_Window* window=NULL;
SDL_Renderer* ren=NULL;
SDL_Texture *tPea=NULL;
SDL_Texture *tBasicZombie=NULL;
SDL_Texture *tPeashooter=NULL;
SDL_Texture *tSun=NULL;
SDL_Texture* loadIMG( const char* s)
{
    SDL_Surface* tmpSurface;
    tmpSurface=IMG_Load(s);
    SDL_Texture* tex =NULL;
    tex = SDL_CreateTextureFromSurface(ren,tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}

