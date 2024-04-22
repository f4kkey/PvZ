#include "board.h"
board::board()
{
    int x=50;
    for(int i=0;i<9;i++)
    {
        int y=250;
        for(int j=0;j<5;j++)
        {
            pos[i][j]={x,y,TILE_WIDTH-1,TILE_HEIGHT-1};
            y+=TILE_HEIGHT;
        }
        x+=TILE_WIDTH;
    }
    for(int row=0;row<5;row++) l[row]=new lawnmover,l[row]->setRow(row);
    levelFile.open("resources/others/level.txt");
    int curLevel=0,totalWave,wave;
    while(!levelFile.eof())
    {
        levelFile>>totalWave;
        for(int i=1;i<=totalWave;i++)
        {
            levelFile>>wave;
            level[curLevel].push_back(wave);
        }
        curLevel++;
    }
    preWave=0;
    curWave=0;
    finalWaveRect={-100,-100,SCREEN_WIDTH+200,SCREEN_HEIGHT+200};
}
SDL_Rect board::pos[9][5];
bool board::exist[9][5];
vector<zombie*> board::z[5];
vector<plant*> board::p[5];
vector<pea*> board::pe[5];
void board::reset()
{
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:z[i]) delete tmp;
        z[i].clear();
        for(auto &tmp:p[i]) delete tmp;
        p[i].clear();
        for(auto &tmp:pe[i]) delete tmp;
        pe[i].clear();
    }
    for(int i=0;i<9;i++) for(int j=0;j<5;j++) exist[i][j]=0;
    finalWave=0;
    curWave=0;
    preWave=SDL_GetTicks();
    finalWaveRect={-100,-100,SCREEN_WIDTH+200,SCREEN_HEIGHT+200};
    for(int row=0;row<5;row++) l[row]->reset();
    s.reset();
}
void board::loadTexture(const char* s)
{
    tex=loadIMG(s);
}
void board::levelProgess(int num)
{
    if(curWave<level[num].size() )
    {
        //20000;
        if(SDL_GetTicks()-preWave>=1000||(curWave!=0&&checkEmpty()))
        {
            if(curWave ==level[num].size()-1&&(!finalWave)) finalWave=1,finalWaveStartTime=SDL_GetTicks();
            spawn(level[num][curWave]);
            curWave++;
            preWave=SDL_GetTicks();
        }
    }

}
void board::spawn(int num)
{
    srand(time(0));
    while(num>0)
    {
        int val=rand()%min(num,3)+1;
        int lane=rand()%5;
        if(val==1)  Z= new basicZombie;
        if(val==2) Z= new coneZombie;
        if(val==3) Z=new bucketZombie;
        Z->spawn(lane);
        z[lane].push_back(Z);
        num-=val;
    }
}
void board::event(SDL_Event e)
{
    s.event(e);
}
void board::update()
{
    s.spawn();
    s.update();
    for(int row=0;row<5;row++)
    {
        for(int i=0;i<p[row].size();i++)
        {
            plant *tmp=p[row][i];
            if(!exist[tmp->getColumn()][row])
            {
                delete tmp;
                p[row].erase(p[row].begin()+i);
            }
        }
        for(int i=0;i<pe[row].size();i++)
        {
            pea *tmp=pe[row][i];
            if(!tmp->alive())
            {
                pe[row].erase(pe[row].begin()+i);
                i--;
                delete tmp;
            }
        }
        for(int i=0;i<z[row].size();i++)
        {
            zombie *tmp=z[row][i];
            if(tmp->disapear())
            {
                z[row].erase(z[row].begin()+i);
                i--;
                delete tmp;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:p[i]) tmp->move();
        for(auto &tmp:pe[i]) tmp->move();
        for(auto &tmp:z[i]) tmp->move();
        l[i]->move();
    }

    if(finalWave&&SDL_GetTicks()-finalWaveStartTime<=3000)
    {
        finalWaveRect.x+=10;
        if(finalWaveRect.x>=300) finalWaveRect.x=300;
        finalWaveRect.y+=10;
        if(finalWaveRect.y>=300) finalWaveRect.y=300;
        finalWaveRect.w-=20;
        if(finalWaveRect.w<=600) finalWaveRect.w=600;
        finalWaveRect.h-=20;
        if(finalWaveRect.h<=200) finalWaveRect.h=200;
    }

}
void board::render()
{
    SDL_RenderCopy(ren,tex,NULL,NULL);
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:p[i]) tmp->render();
        l[i]->render();
        for(auto &tmp:z[i]) tmp->render();
        for(auto &tmp:pe[i]) tmp->render();
    }
    s.render();
    if(finalWave&&SDL_GetTicks()-finalWaveStartTime<=3000) SDL_RenderCopy(ren,tFinalWave,NULL,&finalWaveRect);

}
bool board::checkEmpty()
{
    for(int i=0;i<5;i++) if(z[i].size()) return 0;
    return 1;
}

