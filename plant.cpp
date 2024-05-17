#include "plant.h"
#include "board.h"
plant::plant()
{
    pos.w=PLANT_WIDTH;
    pos.h=PLANT_HEIGHT;
    column=-1;
    prePlantTime=-60000; //plant from the cursor are ready
}
void plant::render()
{

}
void plant::move()
{

}
void plant::preRender()
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(inside(x,y,board::pos[i][j])&&!board::exist[i][j])
            {
                SDL_Rect tmp=board::pos[i][j];
                tmp.x+=20;
                tmp.y-=20;
                tmp.w=PLANT_WIDTH;
                tmp.h=PLANT_HEIGHT;
                SDL_RenderCopy(ren,tPlant2[value],NULL,&tmp);
            }
        }
    }
}
void plant::spawn(int i,int j)
{
    if(board::exist[i][j]) return;
    column=i;
    row=j;
    pos.x=board::pos[i][j].x+20;
    pos.y=board::pos[i][j].y-20;
    board::exist[i][j]=1;
    preFireTime=prePlantTime=SDL_GetTicks();
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
