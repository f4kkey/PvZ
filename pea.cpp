#include "pea.h"
#include "board.h"
pea::pea()
{
    pos.w=pos.h=30;
    v=6;
    live=1;
    damage=20;
}
void pea::spawn(int i,int j)
{
    column=i;
    row=j;
    pos.x=board::pos[i][j].x+90;
    pos.y=board::pos[i][j].y;
}
void pea::move()
{
    pos.x+=v;
    for(int j=0;j<board::z[row].size();j++)
    {
        zombie *tmp=board::z[row][j];
        SDL_Rect tmpPos=pos;
        tmpPos.x-=20;
        if(tmp->alive()&&collision(tmpPos,tmp->getPos()))
        {
            tmp->takeDamage(damage);
            live=0;
            Mix_PlayChannel(-1,mSplat,0);
            break;
        }
    }
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
bool pea::alive()
{
    return live;
}
