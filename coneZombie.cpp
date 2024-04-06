#include "basicZombie.h"
#include "board.h"
coneZombie::coneZombie()
{
    health=550;
    damage=50;
    pos.w=60;
    pos.h=150;
    pos.x=SCREEN_WIDTH;
    v=1;
    live=1;
    val=1;
    walkSpeed=40;
    walkTime=preWalkTime=0;
    biteSpeed=500;
    isBiting=0;
    biteTime=preBiteTime=0;
}
void coneZombie::render()
{
    SDL_RenderCopy(ren,tConeZombie,NULL,&pos);
}
void coneZombie::move()
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
        pos.y=board::pos[0][row].y+TILE_HEIGHT-pos.h;
        pos.x-=v;
        if(pos.x+pos.w<0) pos.x=-pos.w;
        preWalkTime=walkTime;
    }
}
