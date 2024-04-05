#include "all.h"
SDL_Window* window=NULL;
SDL_Renderer* ren=NULL;
SDL_Texture *tPea=NULL;
SDL_Texture *tBasicZombie=NULL;
SDL_Texture *tPeashooter=NULL;
SDL_Texture *tSunFlower=NULL;
SDL_Texture *tShovel=NULL;
SDL_Texture *tSun=NULL;
SDL_Texture *tLawnmover=NULL;
SDL_Texture *tWallnut=NULL;
SDL_Texture *tCherryBomb=NULL;
TTF_Font *font=NULL;
int mousePosX,mousePosY;
SDL_Texture* loadIMG( const char* s)
{
    SDL_Surface* tmpSurface;
    tmpSurface=IMG_Load(s);
    SDL_Texture* tex =NULL;
    tex = SDL_CreateTextureFromSurface(ren,tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}
bool inside(int x,int y,SDL_Rect rect)
{
    if(x>=rect.x&&x<=rect.x+rect.w&&y>=rect.y&&y<=rect.y+rect.h) return 1;
    return 0;
}
bool collision(SDL_Rect A,SDL_Rect B)
{
    if(A.x>B.x+B.w||A.x+A.w<B.x||A.y+A.h<B.y||B.y+B.h<A.y) return false;
    return true;
}

