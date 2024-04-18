#include "lawnmover.h"
#include "board.h"
lawnmover::lawnmover()
{
    used=0;
    pos.x=-50;
    v=1;
    pos.h=100;
    pos.w=100;
}
void lawnmover::reset()
{
    used=0;
    pos.x=-50;
}
void lawnmover::setRow(int i)
{
    row=i;
    pos.y=board::pos[0][i].y;
}
void lawnmover::move()
{
    if(used)
    {
        if(pos.x>SCREEN_WIDTH) return;
        else
        {
            pos.x+=v;
            for(int i=0;i<board::z[row].size();i++)
            {
                zombie *tmp=board::z[row][i];
                if(collision(pos,tmp->getPos()))
                {
                    board::z[row].erase(board::z[row].begin()+i);
                    i--;
                    delete tmp;
                }
            }
        }
    }
    else
    {
        for(auto &tmp:board::z[row] )
        {
            if(collision(pos,tmp->getPos()))
            {
                used=1;
            }
        }
    }
}
void lawnmover::render()
{
//    cout<<pos.x<<" "<<pos.y<<"\n";
    SDL_RenderCopy(ren,tLawnmover,NULL,&pos);
}
