#include "potatoMine.h"
#include "board.h"
potatoMine::potatoMine()
{
    price=25;
    live=1;
    health=300;
    fireInterval=14000;
    damage=1300;
    sprite[0].x=0;
    sprite[0].y=40;
    sprite[0].w=100;
    sprite[0].h=80;

    sprite[1].x=100;
    sprite[1].y=0;
    sprite[1].w=100;
    sprite[1].h=120;
    v=2;
    recharge=30000;
    preFireTime=0;
    value=4;
    explosionTime=-1;
}
void potatoMine::render()
{
    if(column==-1)
    {
        if(SDL_GetTicks()-prePlantTime<recharge)
        {
            rechargeRect=pos;
            rechargeRect.h=pos.h*(recharge-SDL_GetTicks()+prePlantTime)/recharge;
            SDL_RenderCopy(ren,tBlank,NULL,&rechargeRect);
        }
    }
    else
    {
        if(SDL_GetTicks()-preFireTime>=fireInterval&&sprite[0].h<100) sprite[0].h+=v,sprite[0].y+=v;
    }
    if(live)SDL_RenderCopy(ren,tPlant[4],&sprite[0],&pos);
    else SDL_RenderCopy(ren,tPlant[4],&sprite[1],&radius);
}
void potatoMine::move()
{
    if(SDL_GetTicks()-preFireTime>=fireInterval)
    {
        if(live)
        {
            for(auto &tmp:board::z[row])
            {
                if(collision(pos,tmp->getPos()))
                {
                    live=0;
                    break;
                }
            }
        }
        else
        {
            if(explosionTime==-1)
            {
                Mix_PlayChannel(-1,mPotatoMine,0);
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
                explosionTime=SDL_GetTicks();
            }
            else if(SDL_GetTicks()-explosionTime>=1000)
            {
                    board::exist[column][row]=0;
            }
        }
    }
}
void potatoMine::spawn(int i,int j)
{
    plant::spawn(i,j);
    sprite[0].y=0;
    radius.x = board::pos[column][row].x-TILE_WIDTH/2;
    radius.y = board::pos[column][row].y;
    radius.w = TILE_WIDTH*2;
    radius.h = TILE_HEIGHT;
}
void potatoMine::preRender()
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(inside(x,y,board::pos[i][j]))
            {
                SDL_Rect tmp=board::pos[i][j];
                tmp.x+=20;
                tmp.y-=20;
                tmp.w=PLANT_WIDTH;
                tmp.h=PLANT_HEIGHT;
                SDL_RenderCopy(ren,tPlant2[value],&sprite[0],&tmp);
            }
        }
    }
}
