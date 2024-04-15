#include "board.h"
board::board()
{
    int x=50;
    for(int i=0;i<9;i++)
    {
        int y=250;
        for(int j=0;j<5;j++)
        {
            pos[i][j]={x,y,120,100};
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
void board::loadTexture(const char* s)
{
    tex=loadIMG(s);
}
void board::start()
{

}
void board::levelProgess(int num)
{

    if(curWave<level[num].size() )
    {
        if(SDL_GetTicks()-preWave>=15000||(curWave!=0&&checkEmpty()))
        {
            spawn(level[num][curWave]);
            curWave++;
            preWave=SDL_GetTicks();
        }
    }
    if(curWave ==level[num].size()-1) finalWave=1,finalWaveStartTime=SDL_GetTicks();
}
void board::spawn(int num)
{
    srand(time(0));
    while(num>0)
    {
        int val=rand()%min(num,2)+1;
        int lane=rand()%5;
//        cout<<val<<"\n";
        if(val==1)
        {
            Z1= new basicZombie;
            Z1->spawn(lane);
            z[lane].push_back(Z1);
        }
        if(val==2)
        {
            Z2= new coneZombie;
            Z2->spawn(lane);
            z[lane].push_back(Z2);
        }
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
    }
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:p[i]) tmp->move();
        for(auto &tmp:z[i]) tmp->move();
        for(auto &tmp:pe[i]) tmp->move();
        for(int row=0;row<5;row++) l[row]->move();
    }
    for(int row=0;row<5;row++)
    {
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
    }
    if(finalWave&&SDL_GetTicks()-finalWaveStartTime<=5000)
    {
        finalWaveRect.x+=10;
        if(finalWaveRect.x>=400) finalWaveRect.x=400;
        finalWaveRect.y+=10;
        if(finalWaveRect.y>=300) finalWaveRect.y=300;
        finalWaveRect.w-=20;
        if(finalWaveRect.w>=400) finalWaveRect.w=400;
        finalWaveRect.h-=20;
        if(finalWaveRect.h>=200) finalWaveRect.w=200;
    }
}
void board::render()
{
    SDL_RenderCopy(ren,tex,NULL,NULL);
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:p[i]) tmp->render();
        for(auto &tmp:z[i]) tmp->render();
        for(auto &tmp:pe[i]) tmp->render();
        for(int row=0;row<5;row++) l[row]->render();
    }
    s.render();
    if(finalWave&&SDL_GetTicks()-finalWaveStartTime<=5000) SDL_RenderCopy(ren,tFinalWave,NULL,&finalWaveRect);

}
bool board::checkEmpty()
{
    for(int i=0;i<5;i++) if(z[i].size()) return 0;
    return 1;
}

