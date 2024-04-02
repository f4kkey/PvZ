#include "basicZombie.h"
basicZombie::basicZombie()
{

    health=300;
    damage=40;
    pos.w=40;
    pos.h=130;
    pos.x=SCREEN_WIDTH;
    v=1;
    live=1;
    walkSpeed=35;
    walkTime=preWalkTime=0;
    biteSpeed=300;
    isBiting=0;
    biteTime=preBiteTime=0;
}
void basicZombie::move()
{
    if(isBiting) return;
    walkTime=SDL_GetTicks();
    if(walkTime-preWalkTime>=walkSpeed)
    {
        pos.y=lanePos[lane]-pos.h;
        pos.x-=v;
        if(pos.x<0) pos.x=0;
        preWalkTime=walkTime;
    }
}
void basicZombie::render()
{
    SDL_RenderCopy(ren,tBasicZombie,NULL,&pos);
}
void basicZombie::spawn(int x)
{
    if(x==5)
    {
        srand(time(0));
        lane=rand()%5;
    }
    else lane=x;

}
SDL_Rect basicZombie::getPos()
{
    return pos;
}
void basicZombie::takeDamage(int damageTaken)
{
    health-=damageTaken;
    if(health<=0) live=0;
}
bool basicZombie::alive()
{
    return live;
}
int basicZombie::bite()
{
    biteTime=SDL_GetTicks();
    if(biteTime-preBiteTime>=biteSpeed)
    {
        preBiteTime=biteTime;
        return damage;
    }
    return 0;
}
void basicZombie::biting(bool mask)
{
    isBiting=mask;
}
