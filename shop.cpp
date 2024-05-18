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
    cursor=new peashooter;
    p.push_back(cursor);
    cursor=new sunFlower();
    p.push_back(cursor);
    cursor=new wallnut();
    p.push_back(cursor);
    cursor=new cherryBomb();
    p.push_back(cursor);
    cursor=new potatoMine();
    p.push_back(cursor);
    cursor=new repeater();
    p.push_back(cursor);
    cursor=new shovel();
    p.push_back(cursor);
    for(int i=0;i<7;i++) p[i]->setPos(seedPos[i+1].x,seedPos[i+1].y);
    cursor=new plant;

    pickVal=-1;
}
void shop::reset()
{
    //20000
    for(int i=0;i<6;i++) p[i]->setPlantTime(SDL_GetTicks()-20000);
    preSunSpawnTime=SDL_GetTicks()-5000;
    totalSun=50;
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
    priceText=SDL_CreateTextureFromSurface(ren,tmpSurface);
    textWidth=tmpSurface->w;
    textHeight=tmpSurface->h;
    SDL_FreeSurface(tmpSurface);
    SDL_Rect tmp={seedPricePos[i].x+(seedPricePos[i].w-textWidth)/2,seedPricePos[i].y+(seedPricePos[i].h-textHeight)/2,textWidth,textHeight};
    SDL_RenderCopy(ren,priceText,NULL,&tmp);
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
        if(pickVal==-1 )
        {
            SDL_GetMouseState(&mousePosX,&mousePosY);
            for(int i=0;i<7;i++)
            {
                if(inside(mousePosX,mousePosY,seedPos[i+1])&&totalSun>=p[i]->getPrice()&&p[i]->plantable())
                {
                    SDL_ShowCursor(SDL_DISABLE),pickVal=i;
                    Mix_PlayChannel(-1,mSeedPacket,0);
                }
            }
            if(pickVal==0) cursor=new peashooter;
            if(pickVal==1) cursor=new sunFlower;
            if(pickVal==2) cursor=new wallnut;
            if(pickVal==3) cursor=new cherryBomb;
            if(pickVal==4) cursor=new potatoMine;
            if(pickVal==5) cursor=new repeater;
            if(pickVal==6) cursor=new shovel;
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
                            placePlant(i,j,pickVal);
                        }
                    }
                }
            }
            pickVal=-1;
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
    if(pickVal!=-1)
    {
        SDL_GetMouseState(&mousePosX,&mousePosY);
        cursor->setPos(mousePosX-TILE_WIDTH/3,mousePosY-TILE_HEIGHT/2);
        cursor->render();
        if(pickVal!=6) cursor->preRender();
    }
}
void shop::placePlant(int column,int row,int val)
{
    if(pickVal>=0&&pickVal<=5)
    {
        if(board::exist[column][row]) return;
        totalSun-=cursor->getPrice();
        cursor->spawn(column,row);
        board::p[row].push_back(cursor);
        p[pickVal]->setPlantTime(SDL_GetTicks());
        Mix_PlayChannel(-1,mPlant,0);
    }
    else
    {
        if(board::exist[column][row]) Mix_PlayChannel(-1,mPlant,0);
        board::exist[column][row]=0;
    }
}
