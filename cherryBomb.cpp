#include "cherryBomb.h"
#include "board.h"
cherryBomb::cherryBomb()
{
    price=150;
    live=1;
    health=999999999;
    fireInterval=1200;
    damage=1300;
    recharge=50000;
    explodeTime=-1;
    for(int i=0;i<2;i++)
    {
        sprite[i].x=100*i-1;
        sprite[i].y=0;
        sprite[i].w=100;
        sprite[i].h=120;
    }
}
void cherryBomb::render()
{
    if(explodeTime==-1)SDL_RenderCopy(ren,tPlant[3],&sprite[0],&pos);
    else SDL_RenderCopy(ren,tPlant[3],&sprite[1],&radius);
    if(column==-1)
    {
        if(SDL_GetTicks()-prePlantTime<recharge)
        {
            rechargeRect=pos;
            rechargeRect.h=pos.h*(recharge-SDL_GetTicks()+prePlantTime)/recharge;
            SDL_RenderCopy(ren,tBlank,NULL,&rechargeRect);
        }
    }
}
void cherryBomb::move()
{
//    cout<<fireTime<<" "<<preFireTime<<"\n";
    radius.x = board::pos[column][row].x-TILE_WIDTH;
    radius.y = board::pos[column][row].y-TILE_HEIGHT;
    radius.w = TILE_WIDTH*3;
    radius.h = TILE_HEIGHT*3;
    if(SDL_GetTicks()-preFireTime>=fireInterval)
    {
        if(explodeTime==-1)
        {
            Mix_PlayChannel(-1,mCherryBomb,0);
            for(int j=0;j<board::z[row].size();j++)
            {
                zombie *tmp=board::z[row][j];
                if(collision(radius,tmp->getPos()))
                {
                    tmp->takeDamage(damage);
                    if(!tmp->alive())
                    {
                        delete tmp;
                        board::z[row].erase(board::z[row].begin()+j);
                        j--;
                    }
                }
            }
            if(row>0)
            for(int j=0;j<board::z[row-1].size();j++)
            {
                zombie *tmp=board::z[row-1][j];
                if(collision(radius,tmp->getPos()))
                {
                    tmp->takeDamage(damage);
                    if(!tmp->alive())
                    {
                        delete tmp;
                        board::z[row-1].erase(board::z[row-1].begin()+j);
                        j--;
                    }
                }
            }
            if(row<4)
            for(int j=0;j<board::z[row+1].size();j++)
            {
                zombie *tmp=board::z[row+1][j];
                if(collision(radius,tmp->getPos()))
                {
                    tmp->takeDamage(damage);
                    if(!tmp->alive())
                    {
                        delete tmp;
                        board::z[row+1].erase(board::z[row+1].begin()+j);
                        j--;
                    }
                }
            }
            explodeTime=SDL_GetTicks();
        }
        else
        {
            if(SDL_GetTicks()-explodeTime>=1000)
            {
                live=0;
                board::exist[column][row]=0;
            }
        }
    }
}
