#include "repeater.h"
#include "board.h"
repeater::repeater()
{
    price=200;
    live=1;
    health=300;
    fireSpeed=1425;
    tmpFireSpeed[0]=1425;
    tmpFireSpeed[1]=200;
    type=0;
    pos.w=100;
    pos.h=120;
    recharge=7500;
}
void repeater::render()
{
    SDL_RenderCopy(ren,tPlant[5],NULL,&pos);
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
void repeater::move()
{
    for(auto &tmp:board::z[row])
    {
        SDL_Rect zomPos=tmp->getPos();
        if(pos.x+pos.w<=zomPos.x)
        {
            fireTime=SDL_GetTicks();
            if(fireTime-preFireTime>=tmpFireSpeed[type])
            {
                type=1-type;
                preFireTime=fireTime;
                bullet=new pea;
                bullet->spawn(column,row);
                board::pe[row].push_back(bullet);
                break;
            }

        }
    }
}
void repeater::spawn(int i,int j)
{
    plant::spawn(i,j);
    preFireTime=SDL_GetTicks();
}
