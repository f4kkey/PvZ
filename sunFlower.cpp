#include "sunFlower.h"
#include "shop.h"
sunFlower::sunFlower()
{
    price=50;
    live=1;
    health=300;
    fireSpeed=8000;
    pos.w=80;
    pos.h=100;
    fireTime=preFireTime=0;
}
void sunFlower::render()
{
    SDL_RenderCopy(ren,tSunFlower,NULL,&pos);
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
