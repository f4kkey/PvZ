#include "wallnut.h"
#include "board.h"
wallnut::wallnut()
{
    price=50;
    live=1;
    health=4000;
    for(int i=0;i<3;i++)
    {
        sprite[i].x=100*i;
        sprite[i].y=0;
        sprite[i].w=100;
        sprite[i].h=120;
    }
    recharge=30000;
    value=2;
}
void wallnut::render()
{
    if(health>=2500) SDL_RenderCopy(ren,tPlant[2],&sprite[0],&pos);
    else if(health>=1500) SDL_RenderCopy(ren,tPlant[2],&sprite[1],&pos);
    else SDL_RenderCopy(ren,tPlant[2],&sprite[2],&pos);
    if(column==-1)
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
void wallnut::preRender()
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(inside(x,y,board::pos[i][j])&&!board::exist[i][j])
            {
                SDL_Rect tmp=board::pos[i][j];
                tmp.x+=20;
                tmp.y-=20;
                tmp.w=PLANT_WIDTH;
                tmp.h=PLANT_HEIGHT;
                SDL_RenderCopy(ren,tPlant2[value],&sprite[0],&tmp);
            }
        }
    }
}
