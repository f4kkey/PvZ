#include "wallnut.h"
wallnut::wallnut()
{
    price=50;
    live=1;
    health=4000;
    pos.w=100;
    pos.h=120;
    for(int i=0;i<3;i++)
    {
        sprite[i].x=100*i-1;
        sprite[i].y=0;
        sprite[i].w=100;
        sprite[i].h=120;
    }
    recharge=15000;
}
void wallnut::render()
{
    if(health>=3500) SDL_RenderCopy(ren,tWallnut,&sprite[0],&pos);
    else if(health>=3000) SDL_RenderCopy(ren,tWallnut,&sprite[1],&pos);
    else SDL_RenderCopy(ren,tWallnut,&sprite[2],&pos);
    if(!column&&!picked)
    {
        if(SDL_GetTicks()-prePlantTime<recharge)
        {
            rechargeRect=pos;
            rechargeRect.h=pos.h*(recharge-SDL_GetTicks()+prePlantTime)/recharge;
            SDL_RenderCopy(ren,tBlank,NULL,&rechargeRect);
        }
    }
}
void wallnut::move()
{

}
