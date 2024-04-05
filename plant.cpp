#include "plant.h"
#include "board.h"
plant::plant()
{
    picked=0;
}
void plant::spawn(int i,int j)
{
    if(board::exist[i][j]) return;
    column=i;
    row=j;
    pos.x=board::pos[i][j].x+30;
    pos.y=board::pos[i][j].y-30;
//    cout<<pos.x<<" "<<pos.y<<"\n";
    board::exist[i][j]=1;
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
bool plant::isPicked()
{
    return picked;
}
void plant::changePickState()
{
    picked=1-picked;
}
