#include "zombie.h"
zombie::zombie()
{

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
