#include "pea.h"
#include "board.h"
pea::pea()
{
    pos.w=pos.h=30;
    v=6;
    live=1;
    damage=30;
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
        if(collision(pos,tmp->getPos()))
        {
            tmp->takeDamage(damage);
            live=0;
            if(!tmp->alive())
            {
                delete tmp;
                board::z[row].erase(board::z[row].begin()+j);
            }
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
