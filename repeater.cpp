#include "repeater.h"
#include "board.h"
repeater::repeater()
{
    price=200;
    live=1;
    health=300;
    fireInterval=1425;
    tmpFireInterval[0]=1425;
    tmpFireInterval[1]=200;
    type=0;
    recharge=7500;
}
void repeater::render()
{
    SDL_RenderCopy(ren,tPlant[5],NULL,&pos);
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
void repeater::move()
{
    for(auto &tmp:board::z[row])
    {
        SDL_Rect zomPos=tmp->getPos();
        if(pos.x+pos.w<=zomPos.x)
        {
            if(SDL_GetTicks()-preFireTime>=tmpFireInterval[type])
            {
                type=1-type;
                preFireTime=SDL_GetTicks();
                bullet=new pea;
                bullet->spawn(column,row);
                board::pe[row].push_back(bullet);
                break;
            }

        }
    }
}
