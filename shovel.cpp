#include "shovel.h"
shovel::shovel()
{
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
