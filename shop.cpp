#include "shop.h"
#include "board.h"
shop::shop()
{
    sunSpawnTime=preSunSpawnTime=0;
    sunSpawnSpeed=9000;
    for(int i=0;i<8;i++)
    {
        seedPos[i].x=(i)*100;
        seedPos[i].w=99;
        seedPos[i].h=120;
        seedPricePos[i].x=(i)*100;
        seedPricePos[i].y=120;
        seedPricePos[i].w=99;
        seedPricePos[i].h=30;
    }
    ps=new peashooter;
    p.push_back(ps);
    sf=new sunFlower();
    p.push_back(sf);
    wn=new wallnut();
    p.push_back(wn);
    cb=new cherryBomb();
    p.push_back(cb);
    pm=new potatoMine();
    p.push_back(pm);
    rp=new repeater();
    p.push_back(rp);
    sv=new shovel();
    p.push_back(sv);
    for(int i=0;i<7;i++) p[i]->setPos(seedPos[i+1].x,seedPos[i+1].y);
    cursor=new plant;

    pickVal=0;
}
void shop::reset()
{
    //20000
    for(int i=0;i<6;i++) p[i]->setPlantTime(SDL_GetTicks()-60000);
    preSunSpawnTime=SDL_GetTicks()-5000;
    totalSun=500;
    for(auto &tmp:s) delete tmp;
    s.clear();
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
    }

    if(e.type==SDL_MOUSEBUTTONDOWN)
    {
        if(!pickVal )
        {
            SDL_GetMouseState(&mousePosX,&mousePosY);
            for(int i=0;i<7;i++)
            {
                if(inside(mousePosX,mousePosY,seedPos[i+1])&&totalSun>=p[i]->getPrice()&&p[i]->plantable())
                {
                    SDL_ShowCursor(SDL_DISABLE),pickVal=i+1;
                    Mix_PlayChannel(-1,mPlant,0);
                }
            }
            if(pickVal==1) cursor=new peashooter;
            if(pickVal==2) cursor=new sunFlower;
            if(pickVal==3) cursor=new wallnut;
            if(pickVal==4) cursor=new cherryBomb;
            if(pickVal==5) cursor=new potatoMine;
            if(pickVal==6) cursor=new repeater;
            if(pickVal==7) cursor=new shovel;
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
                            Mix_PlayChannel(-1,mPlant,0);
                        }
                    }
                }
            }
            pickVal=0;
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
}
void shop::render()
{
    SDL_RenderCopy(ren,tSun,NULL,&seedPos[0]);
    renderText(totalSun,0);
    for(int i=0;i<7;i++)
    {
        p[i]->render();
        if(i!=6) renderText(p[i]->getPrice(),i+1);
    }
    for(auto &tmp:s) tmp->render();
    if(pickVal)
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
    p[pickVal-1]->setPlantTime(SDL_GetTicks());
}
