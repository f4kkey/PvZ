#include "peashooter.h"
#include "board.h"
peashooter::peashooter()
{
    price=100;
    live=1;
    health=300;
    fireInterval=1425;
    recharge=7500;
    value=0;
}
void peashooter::render()
{
    SDL_RenderCopy(ren,tPlant[0],NULL,&pos);
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
void peashooter::move()
{
    for(auto &tmp:board::z[row])
    {
        if(!tmp->alive()) continue;
        SDL_Rect zomPos=tmp->getPos();
        if(pos.x+pos.w<=zomPos.x)
        {
            if(SDL_GetTicks()-preFireTime>=fireInterval)
            {
                preFireTime=SDL_GetTicks();
                bullet=new pea;
                bullet->spawn(column,row);
                board::pe[row].push_back(bullet);
                break;
            }

        }
    }
}
