#include "repeater.h"
#include "board.h"
repeater::repeater()
{
    price=200;
    live=1;
    health=300;
    fireSpeed=2000;
    tmpFireSpeed[0]=2000;
    tmpFireSpeed[1]=500;
    type=0;
    pos.w=80;
    pos.h=100;
    fireTime=preFireTime=0;
}
void repeater::render()
{
    SDL_RenderCopy(ren,tRepeater,NULL,&pos);
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
