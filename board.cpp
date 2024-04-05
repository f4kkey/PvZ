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
//    s.spawn();
    Z1= new basicZombie;
    Z1->spawn(1);
    z[1].push_back(Z1);
    Z1= new basicZombie;
    Z1->spawn(2);
    z[2].push_back(Z1);
    Z1= new basicZombie;
    Z1->spawn(4);
    z[4].push_back(Z1);

    P=new peashooter;
    P->spawn(0,2);
    p[2].push_back(P);
    P=new peashooter;
    P->spawn(8,1);
    p[1].push_back(P);
    P=new peashooter;
    P->spawn(7,1);
    p[1].push_back(P);
    P=new peashooter;
    P->spawn(2,4);
    p[4].push_back(P);
}
void board::event(SDL_Event e)
{
    s.event(e);
}
void board::update()
{
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

}
bool board::detechZombie(int &row,SDL_Rect position)
{
    for(auto &tmp:z[row])
    {
        if(tmp->getPos().x>=position.x+position.w) return true;
    }
    return false;
}
void board::spawnSun()
{
    s.spawn();
}
