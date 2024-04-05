#include "cherryBomb.h"
#include "board.h"
cherryBomb::cherryBomb()
{
    price=150;
    live=1;
    health=999999999;
    pos.w=80;
    pos.h=100;
    fireSpeed=1000;
    fireTime=preFireTime=0;
    damage=1800;
}
void cherryBomb::render()
{
    SDL_RenderCopy(ren,tCherryBomb,NULL,&pos);
}
void cherryBomb::move()
{
    fireTime=SDL_GetTicks();
    if(fireTime-preFireTime>=fireSpeed)
    {
        live=0;
        board::exist[column][row]=0;
        radius.x = board::pos[column][row].x-TILE_WIDTH;
        radius.y = board::pos[column][row].y-TILE_HEIGHT;
        radius.w = TILE_WIDTH*3;
        radius.h = TILE_HEIGHT*3;
        for(int j=0;j<board::z[row].size();j++)
        {
            zombie *tmp=board::z[row][j];
            if(collision(radius,tmp->getPos()))
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
        if(row>0)
        for(int j=0;j<board::z[row-1].size();j++)
        {
            zombie *tmp=board::z[row-1][j];
            if(collision(radius,tmp->getPos()))
            {
                tmp->takeDamage(damage);
                live=0;
                if(!tmp->alive())
                {
                    delete tmp;
                    board::z[row-1].erase(board::z[row-1].begin()+j);
                }
                break;
            }
        }
        if(row<4)
        for(int j=0;j<board::z[row+1].size();j++)
        {
            zombie *tmp=board::z[row+1][j];
            if(collision(radius,tmp->getPos()))
            {
                tmp->takeDamage(damage);
                live=0;
                if(!tmp->alive())
                {
                    delete tmp;
                    board::z[row+1].erase(board::z[row+1].begin()+j);
                }
                break;
            }
        }
    }

}