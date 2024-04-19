#include "sunFlower.h"
#include "shop.h"
sunFlower::sunFlower()
{
    price=50;
    live=1;
    health=300;
    fireSpeed=20000;
    pos.w=100;
    pos.h=120;
    fireTime=preFireTime=0;
    recharge=7500;
}
void sunFlower::render()
{
    SDL_RenderCopy(ren,tSunFlower,NULL,&pos);
    if(!column)
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
    fireTime=SDL_GetTicks();
    if(fireTime-preFireTime>=fireSpeed)
    {
        s=new sun;
        s->spawn(pos.x-30,pos.y,50);
        s->setEndPos(pos.y+50);
        shop::s.push_back(s);
        preFireTime=fireTime;
    }
}
