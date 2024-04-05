#include "peashooter.h"
#include "board.h"
peashooter::peashooter()
{
    price=100;
    live=1;
    health=300;
    fireSpeed=2500;
    pos.w=80;
    pos.h=100;
    fireTime=preFireTime=0;
}
void peashooter::render()
{
    SDL_RenderCopy(ren,tPeashooter,NULL,&pos);
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
