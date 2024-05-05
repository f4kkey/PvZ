#include "all.h"
SDL_Window* window=NULL;
SDL_Renderer* ren=NULL;
SDL_Texture *tPea=NULL;
SDL_Texture *tBlank=NULL;
SDL_Texture *tFinalWave=NULL;
SDL_Texture *tLevel=NULL;
SDL_Texture *tLose=NULL;
SDL_Texture *tWin=NULL;
TTF_Font *font=NULL;
SDL_Texture *tShovel=NULL;
SDL_Texture *tSun=NULL;
SDL_Texture *tLawnmover=NULL;
int mousePosX,mousePosY;

SDL_Texture *tPlant[7];


SDL_Texture *tHead=NULL;
SDL_Texture *tBody=NULL;
SDL_Texture *tBackLeg=NULL;
SDL_Texture *tFrontLeg=NULL;
SDL_Texture *tBackArm=NULL;
SDL_Texture *tBackFlagArm=NULL;
SDL_Texture *tFrontArm=NULL;
SDL_Texture *tCone=NULL;
SDL_Texture *tCone2=NULL;
SDL_Texture *tCone3=NULL;
SDL_Texture *tBucket=NULL;
SDL_Texture *tBucket2=NULL;
SDL_Texture *tBucket3=NULL;

Mix_Chunk *mEat=NULL;
Mix_Chunk *mSwallow=NULL;
Mix_Chunk *mPlant=NULL;
Mix_Chunk *mSplat=NULL;
Mix_Chunk *mSun=NULL;
Mix_Chunk *mPotatoMine=NULL;
Mix_Chunk *mCherryBomb=NULL;
Mix_Chunk *mFirstWave=NULL;
Mix_Chunk *mSeedPacket=NULL;
Mix_Chunk *mWave=NULL;
Mix_Music *mInGame=NULL;
Mix_Music *mMenu=NULL;
Mix_Music *mWin=NULL;
Mix_Music *mLose=NULL;

SDL_Texture* loadIMG( const char* s)
{
    SDL_Surface* tmpSurface;
    tmpSurface=IMG_Load(s);
    SDL_Texture* tex =NULL;
    tex = SDL_CreateTextureFromSurface(ren,tmpSurface);
    SDL_SetTextureBlendMode(tex,SDL_BLENDMODE_BLEND);
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

