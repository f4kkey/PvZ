#include "shop.h"
#include "board.h"
#include "shovel.h"
shop::shop()
{
    totalSun=50;
    pos={0,0,SCREEN_WIDTH,150};
    sunSpawnTime=preSunSpawnTime=0;
    sunSpawnSpeed=8000;
    for(int i=0;i<8;i++)
    {
        seedPos[i].x=(i)*120;
        seedPos[i].w=120;
        seedPos[i].h=120;
        seedPricePos[i].x=(i)*120;
        seedPricePos[i].y=120;
        seedPricePos[i].w=120;
        seedPricePos[i].h=30;

    }
    ps=new peashooter;
    sf=new sunFlower();
    wn=new wallnut();
    cb=new cherryBomb();
    pm=new potatoMine();
    rp=new repeater();
    cursor=new peashooter();
    pickVal=-1;
}
vector<sun*> shop::s;
void shop::renderText(int v,int i)
{
    stringstream val;
    val.str("");
    val<<v;
    SDL_Color color={0,0,0,255};
    SDL_Surface* tmpSurface=TTF_RenderText_Blended(font,val.str().c_str(),color);
    price=SDL_CreateTextureFromSurface(ren,tmpSurface);
    textWidth=tmpSurface->w;
    textHeight=tmpSurface->h;
    SDL_FreeSurface(tmpSurface);

    SDL_Rect tmp={seedPricePos[i].x+(seedPricePos[i].w-textWidth)/2,seedPricePos[i].y+(seedPricePos[i].h-textHeight)/2,textWidth,textHeight};
    SDL_RenderCopy(ren,price,NULL,&tmp);
}
void shop::event(SDL_Event e)
{
    for(int i=0;i<s.size();i++)
    {
        sun *tmp=s[i];
        int val=s[i]->event(e);
        if(val) totalSun+=val;
        if(!tmp->alive())
        {
            s.erase(s.begin()+i);
            delete tmp;
            i--;
        }
    }
    if(e.type==SDL_MOUSEBUTTONDOWN)
    {
        if(!cursor->isPicked() )
        {
            SDL_GetMouseState(&mousePosX,&mousePosY);
            if(inside(mousePosX,mousePosY,seedPos[1])&&totalSun>=ps->getPrice()) SDL_ShowCursor(SDL_DISABLE),cursor=new peashooter,pickVal=1,cursor->changePickState();
            if(inside(mousePosX,mousePosY,seedPos[2])&&totalSun>=sf->getPrice()) SDL_ShowCursor(SDL_DISABLE),cursor=new sunFlower,pickVal=2,cursor->changePickState();
            if(inside(mousePosX,mousePosY,seedPos[3])&&totalSun>=wn->getPrice()) SDL_ShowCursor(SDL_DISABLE),cursor=new wallnut,pickVal=3,cursor->changePickState();
            if(inside(mousePosX,mousePosY,seedPos[4])&&totalSun>=cb->getPrice()) SDL_ShowCursor(SDL_DISABLE),cursor=new cherryBomb,pickVal=4,cursor->changePickState();
            if(inside(mousePosX,mousePosY,seedPos[5])&&totalSun>=pm->getPrice()) SDL_ShowCursor(SDL_DISABLE),cursor=new potatoMine,pickVal=5,cursor->changePickState();
            if(inside(mousePosX,mousePosY,seedPos[6])&&totalSun>=rp->getPrice()) SDL_ShowCursor(SDL_DISABLE),cursor=new repeater,pickVal=6,cursor->changePickState();
            if(inside(mousePosX,mousePosY,seedPos[7])) SDL_ShowCursor(SDL_DISABLE),cursor=new shovel,pickVal=7,cursor->changePickState();
        }
        else
        {
            SDL_GetMouseState(&mousePosX,&mousePosY);
            if(e.button.button==SDL_BUTTON_LEFT)
            {
                for(int i=0;i<9;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        if(inside(mousePosX,mousePosY,board::pos[i][j]))
                        {
                            if(pickVal>=1&&pickVal<=6) placePlant(i,j);
                            if(pickVal==7) board::exist[i][j]=0;
                        }
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
    SDL_RenderCopy(ren,tSun,NULL,&seedPos[0]);
    renderText(totalSun,0);
    SDL_RenderCopy(ren,tPeashooter,NULL,&seedPos[1]);
    renderText(100,1);
    SDL_RenderCopy(ren,tSunFlower,NULL,&seedPos[2]);
    renderText(50,2);
    SDL_RenderCopy(ren,tWallnut,NULL,&seedPos[3]);
    renderText(50,3);
    SDL_RenderCopy(ren,tCherryBomb,NULL,&seedPos[4]);
    renderText(150,4);
    SDL_RenderCopy(ren,tPotatoMine,NULL,&seedPos[5]);
    renderText(25,5);
    SDL_RenderCopy(ren,tRepeater,NULL,&seedPos[6]);
    renderText(200,6);
    SDL_RenderCopy(ren,tShovel,NULL,&seedPos[7]);
    for(auto &tmp:s) tmp->render();
    if(cursor->isPicked())
    {
        SDL_GetMouseState(&mousePosX,&mousePosY);
        cursor->setPos(mousePosX-TILE_WIDTH/3,mousePosY-TILE_HEIGHT/2);
        cursor->render();
    }
}
void shop::placePlant(int column,int row)
{
    if(board::exist[column][row]) return;
    totalSun-=cursor->getPrice();
    cursor->spawn(column,row);
    board::p[row].push_back(cursor);
}
