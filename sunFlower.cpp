#include "sunFlower.h"
#include "shop.h"
sunFlower::sunFlower()
{
    price=50;
    live=1;
    health=300;
    fireInterval=24000;
    pos.w=100;
    pos.h=120;
    recharge=7500;
    value=1;
}
void sunFlower::render()
{
    SDL_RenderCopy(ren,tPlant[1],NULL,&pos);
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
void sunFlower::move()
{
    if(SDL_GetTicks()-preFireTime>=fireInterval)
    {
        s=new sun;
        s->spawn(pos.x-30,pos.y,50);
        s->setEndPos(pos.y+50);
        shop::s.push_back(s);
        preFireTime=SDL_GetTicks();
    }
}
void sunFlower::spawn(int i,int j)
{
    plant::spawn(i,j);
    preFireTime=SDL_GetTicks()-19000;
}

