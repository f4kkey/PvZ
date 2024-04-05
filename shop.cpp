#include "shop.h"
#include "board.h"
#include "shovel.h"
shop::shop()
{
    totalSun=0;
    pos={0,0,SCREEN_WIDTH,150};
    sunSpawnTime=preSunSpawnTime=0;
    sunSpawnSpeed=4000;
    for(int i=0;i<7;i++)
    {
        seedPos[i].x=(i+1)*120;
        seedPos[i].w=120;
        seedPos[i].h=150;
    }
    cursor=new peashooter;
    picked=0;
    pickVal=-1;
}
void shop::event(SDL_Event e)
{
    for(int i=0;i<s.size();i++)
    {
        sun *tmp=s[i];
        if(!tmp->alive())
        {
            s.erase(s.begin()+i);
            delete tmp;
            i--;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        sun *tmp=s[i];
        int val=s[i]->event(e);
        if(val)
        {
            totalSun+=val;
            s.erase(s.begin()+i);
            delete tmp;
            break;
        }
    }
    if(e.type==SDL_MOUSEBUTTONDOWN)
    {
        if(!cursor->isPicked())
        {
            SDL_GetMouseState(&mousePosX,&mousePosY);
            if(inside(mousePosX,mousePosY,seedPos[0])) SDL_ShowCursor(SDL_DISABLE),cursor=new peashooter,pickVal=0,cursor->changePickState();
            if(inside(mousePosX,mousePosY,seedPos[6])) SDL_ShowCursor(SDL_DISABLE),cursor=new shovel,pickVal=6,cursor->changePickState();
        }
        else
        {
            SDL_GetMouseState(&mousePosX,&mousePosY);
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(inside(mousePosX,mousePosY,board::pos[i][j]))
                    {
                        if(pickVal==0) placePeaShooter(i,j);
                        if(pickVal==6) board::exist[i][j]=0;
                    }
                }
            }
            cursor->changePickState();
            SDL_ShowCursor(SDL_ENABLE);
        }
    }
}
void shop::spawn()
{
    sunSpawnTime=SDL_GetTicks();

    if(sunSpawnTime-preSunSpawnTime>=sunSpawnSpeed)
    {
        preSunSpawnTime=sunSpawnTime;
        S=new sun;
        S->spawn();
        s.push_back(S);
    }
}
void shop::update()
{
    for(auto &tmp:s)
    {
        tmp->move();
    }
}
void shop::render()
{
    SDL_RenderCopy(ren,tPeashooter,NULL,&seedPos[0]);
    SDL_RenderCopy(ren,tShovel,NULL,&seedPos[6]);
    for(auto &tmp:s)
    {
        tmp->render();
    }
//    cout<<cursor->isPicked()<<"\n";
    if(cursor->isPicked())
    {
//        cout<<"lmao\n";
        SDL_GetMouseState(&mousePosX,&mousePosY);
        cursor->setPos(mousePosX-TILE_WIDTH/2,mousePosY-TILE_HEIGHT);
        cursor->render();
    }
}
void shop::placePeaShooter(int column,int row)
{
    if(board::exist[column][row]) return;
    cursor->spawn(column,row);
    board::p[row].push_back(cursor);
}
