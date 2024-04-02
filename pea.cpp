#include "pea.h"
pea::pea()
{
    pos.w=pos.h=30;
    v=6;
    live=1;
}
void pea::spawn(int x,int y)
{
    pos.x=x;
    pos.y=y;
}
void pea::move()
{
    pos.x+=v;
}
void pea::render()
{
    SDL_RenderCopy(ren,tPea,NULL,&pos);
}
SDL_Rect pea::getPos()
{
    return pos;
}
int pea::getDamage()
{
    return damage;
}
