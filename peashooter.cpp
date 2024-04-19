#include "peashooter.h"
#include "board.h"
peashooter::peashooter()
{
    price=100;
    live=1;
    health=300;
    fireSpeed=1425;
    pos.w=100;
    pos.h=120;
    recharge=7500;
    fireTime=preFireTime=0;
}
void peashooter::render()
{
    SDL_RenderCopy(ren,tPeashooter,NULL,&pos);
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
void peashooter::move()
{
    for(auto &tmp:board::z[row])
    {
        SDL_Rect zomPos=tmp->getPos();
        if(pos.x+pos.w<=zomPos.x)
        {
            fireTime=SDL_GetTicks();
            if(fireTime-preFireTime>=fireSpeed)
            {
                preFireTime=fireTime;
                bullet=new pea;
                bullet->spawn(column,row);
                board::pe[row].push_back(bullet);
                break;
            }

        }
    }
}
