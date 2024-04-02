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
    walkTime=walkPreTime=0;
}
void basicZombie::move()
{
    walkTime=SDL_GetTicks();
    if(walkTime-walkPreTime>40)
    {
//        cout<<walkTime<<" "<<walkPreTime<<"\n";
        pos.y=lanePos[lane]-pos.h;
        pos.x-=v;
        if(pos.x<0) pos.x=0;
        walkPreTime=walkTime;
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
bool basicZombie::checkStatus()
{
    return live;
}
