#include "peashooter.h"

peashooter::peashooter()
{
    health=300;
    fireRate=2000;
    pos.w=80;
    pos.h=100;
    fireTime=preFireTime=0;
}
void peashooter::render()
{
    SDL_RenderCopy(ren,tPeashooter,NULL,&pos);
}
void peashooter::spawn(int &x,int &y)
{
    pos.x=x+30;
    pos.y=y-30;
}
SDL_Rect peashooter::getPos()
{
    return pos;
}
bool peashooter::fire()
{
    fireTime=SDL_GetTicks();
    if(fireTime-preFireTime>=fireRate)
    {
//        cout<<fireTime<<" "<<preFireTime<<"\n";
        preFireTime=fireTime;
//        cout<<" "<<fireTime<<" "<<preFireTime<<"\n";
        return true;
    }
    return false;
}
