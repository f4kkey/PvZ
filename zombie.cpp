#include "zombie.h"
zombie::zombie()
{
    damage=50;
    v=1;
    live=1;
    val=1;
    walkSpeed=65;
    walkTime=preWalkTime=0;
    biteSpeed=500;
    isBiting=0;
    biteTime=preBiteTime=0;

    handAngle=legAngle=0;
    vLeg=vHand=1;
    handCenter={50,60};
    pos.w=100;
    pos.h=170;
    pos.x=SCREEN_WIDTH;
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
