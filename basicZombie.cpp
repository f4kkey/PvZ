#include "basicZombie.h"
#include "board.h"
basicZombie::basicZombie()
{
    health=300;
    damage=40;
    pos.w=40;
    pos.h=130;
    pos.x=SCREEN_WIDTH;
    v=1;
    live=1;
    val=1;
    walkSpeed=30;
    walkTime=preWalkTime=0;
    biteSpeed=300;
    isBiting=0;
    biteTime=preBiteTime=0;
}
void basicZombie::render()
{
    SDL_RenderCopy(ren,tBasicZombie,NULL,&pos);
}
void basicZombie::move()
{
    bool obstacle=0;
    for(int j=0;j<board::p[row].size();j++)
    {
        plant *tmp=board::p[row][j];
        if(collision(pos,tmp->getPos()))
        {
            obstacle=1;
            isBiting=1;
            tmp->takeDamage(bite());
            if(!tmp->alive())
            {
                board::exist[tmp->getColumn()][row]=0;
                delete tmp;
                board::p[row].erase(board::p[row].begin()+j);
                isBiting=0;
            }
            break;
        }
    }
    if(!obstacle) isBiting=0;
    if(isBiting) return;
    walkTime=SDL_GetTicks();
    if(walkTime-preWalkTime>=walkSpeed)
    {
        pos.y=lanePos[row]-pos.h;
        pos.x-=v;
        if(pos.x+pos.w<0) pos.x=-pos.w;
        preWalkTime=walkTime;
    }
}
