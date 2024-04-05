#include "wallnut.h"
wallnut::wallnut()
{
    price=50;
    live=1;
    health=4000;
    pos.w=80;
    pos.h=100;
}
void wallnut::render()
{
    SDL_RenderCopy(ren,tWallnut,NULL,&pos);
}
void wallnut::move()
{

}
