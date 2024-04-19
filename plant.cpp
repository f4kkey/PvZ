#include "plant.h"
#include "board.h"
plant::plant()
{
    prePlantTime=-50000;
}
void plant::render()
{

}
void plant::move()
{

}
void plant::spawn(int i,int j)
{
    if(board::exist[i][j]) return;
    column=i;
    row=j;
    pos.x=board::pos[i][j].x+20;
    pos.y=board::pos[i][j].y-20;
    board::exist[i][j]=1;
    preFireTime=SDL_GetTicks();
    sprite.x=0;
    sprite.y=0;
}
void plant::setPlantTime(int x)
{
    prePlantTime=x;
}
void plant::setPos(int x,int y)
{
    pos.x=x;
    pos.y=y;

}
SDL_Rect plant::getPos()
{
    return pos;
}
int plant::getColumn()
{
    return column;
}
int plant::getRow()
{
    return row;
}
bool plant::fire()
{
    fireTime=SDL_GetTicks();
    if(fireTime-preFireTime>=fireSpeed)
    {
        preFireTime=fireTime;
        return true;
    }
    return false;
}
void plant::takeDamage(int damageTaken)
{
    health-=damageTaken;
    if(health<=0) live=0;
}
bool plant::alive()
{
    return live;
}
int plant::getPrice()
{
    return price;
}
bool plant::plantable()
{
    if(SDL_GetTicks()-prePlantTime>=recharge)
    {
        return 1;
    }
    return 0;
}
