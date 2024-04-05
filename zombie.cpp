#include "zombie.h"
zombie::zombie()
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
SDL_Rect zombie::getPos()
{
    return pos;
}
void zombie::spawn(int x)
{
    if(x==5)
    {
        srand(time(0));
        row=rand()%5;
    }
    else row=x;
}
void zombie::takeDamage(int damageTaken)
{
    health-=damageTaken;
    if(health<=0) live=0;
}
bool zombie::alive()
{
    return live;
}
int zombie::bite()
{
    biteTime=SDL_GetTicks();
    if(biteTime-preBiteTime>=biteSpeed)
    {
        preBiteTime=biteTime;
        return damage;
    }
    return 0;
}
void zombie::biting(bool mask)
{
    isBiting=mask;
}
