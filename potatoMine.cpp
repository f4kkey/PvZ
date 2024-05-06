#include "cherryBomb.h"
#include "board.h"
potatoMine::potatoMine()
{
    price=25;
    live=1;
    health=300;
    fireInterval=15000;
    damage=1300;
    sprite.x=0;
    sprite.y=40;
    sprite.w=100;
    sprite.h=80;
    v=2;
    recharge=30000;
    preFireTime=0;
}
void potatoMine::render()
{
    if(SDL_GetTicks()-preFireTime>=fireInterval&&sprite.h<100) sprite.h+=v,sprite.y+=v;
    SDL_RenderCopy(ren,tPlant[4],&sprite,&pos);
    if(!column)
    {

        if(SDL_GetTicks()-prePlantTime<recharge)
        {
            rechargeRect=pos;
            rechargeRect.h=pos.h*(recharge-SDL_GetTicks()+prePlantTime)/recharge;
            SDL_RenderCopy(ren,tBlank,NULL,&rechargeRect);
        }
    }
}
void potatoMine::move()
{
    if(SDL_GetTicks()-preFireTime>=fireInterval)
    {
        for(auto &tmp:board::z[row])
        {
            if(collision(pos,tmp->getPos()))
            {
                live=0;
                board::exist[column][row]=0;
                Mix_PlayChannel(-1,mPotatoMine,0);
                break;
            }
        }
        if(!live)
        {
            radius.x = board::pos[column][row].x-TILE_WIDTH/2;
            radius.y = board::pos[column][row].y;
            radius.w = TILE_WIDTH*2;
            radius.h = TILE_HEIGHT;
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
        }
    }
}
void potatoMine::spawn(int i,int j)
{
    plant::spawn(i,j);
    preFireTime=SDL_GetTicks();
}
