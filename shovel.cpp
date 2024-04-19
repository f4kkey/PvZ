#include "shovel.h"
shovel::shovel()
{
    pos.w=100;
    pos.h=100;
    price=0;
    recharge=0;
    prePlantTime=0;
}
void shovel::render()
{
    SDL_RenderCopy(ren,tShovel,NULL,&pos);
}
void shovel::move()
{

}
