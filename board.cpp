#include "board.h"
board::board()
{
    int x=50;
    for(int i=0;i<9;i++)
    {
        int y=250;
        for(int j=0;j<5;j++)
        {
            pos[i][j]={x,y};
            y+=TILE_HEIGHT;
        }
        x+=TILE_WIDTH;
    }
}
void board::loadTexture(const char* s)
{
    tex=loadIMG(s);
}
void board::start()
{
//    s.spawn();

    Z1.spawn(1);
    z1[1].push_back(Z1);
    Z1.spawn(2);
    z1[2].push_back(Z1);
    Z1.spawn(4);
    z1[4].push_back(Z1);

    P.spawn(pos[0][2].x,pos[0][2].y);
    p[2].push_back(P);
    P.spawn(pos[8][1].x,pos[8][1].y);
    p[1].push_back(P);
    P.spawn(pos[7][1].x,pos[7][1].y);
    p[1].push_back(P);
    P.spawn(pos[2][4].x,pos[2][4].y);
    p[4].push_back(P);
}
void board::event(SDL_Event e)
{
    s.event(e);
}
void board::update()
{
    s.update();
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:p[i])
        {
            SDL_Rect position=tmp.getPos();
            if(tmp.fire())
            {
                if(detechZombie(i,position))
               {
                    PE.spawn(position.x+position.w,position.y+20);
                    pe[i].push_back(PE);
               }
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:z1[i]) tmp.move();
        for(auto &tmp:pe[i]) tmp.move();
    }
    for(int row=0;row<5;row++)
    {
        for(int i=0;i<pe[row].size();i++)
        {
            for(int j=0;j<z1[row].size();j++)
            {
                pea &t1=pe[row][i];
                basicZombie &t2=z1[row][j];
                if(collision(t1.getPos(),t2.getPos()))
                {
                    t2.takeDamage(t1.getDamage());
                    pe[row].erase(pe[row].begin()+i);
                    i--;
                    if(!t2.alive())
                    {
                        z1[row].erase(z1[row].begin()+j);
                    }
                    break;
                }
            }
        }
    }
    for(int row=0;row<5;row++)
    {
        for(int i=0;i<z1[row].size();i++)
        {
            for(int j=0;j<p[row].size();j++)
            {
                basicZombie &t1=z1[row][i];
                peashooter &t2=p[row][j];
                if(collision(t1.getPos(),t2.getPos()))
                {
                    t1.biting(1);
                    t2.takeDamage(t1.bite());
                    if(!t2.alive())
                    {
                        p[row].erase(p[row].begin()+j);
                        t1.biting(0);
                    }

                    break;
                }
            }
        }
    }
}
void board::render()
{
    SDL_RenderCopy(ren,tex,NULL,NULL);
    s.render();
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:p[i]) tmp.render();
        for(auto &tmp:z1[i]) tmp.render();
        for(auto &tmp:pe[i]) tmp.render();
        s.render();

    }
}
bool board::collision(SDL_Rect A,SDL_Rect B)
{
    if(A.x>B.x+B.w||A.x+A.w<B.x||A.y+A.h<B.y||B.y+B.h<A.y) return false;
    return true;
}
bool board::detechZombie(int &row,SDL_Rect position)
{
    for(auto &tmp:z1[row])
    {
        if(tmp.getPos().x>=position.x+position.w) return true;
    }
    return false;
}
void board::spawn()
{
    s.spawn();
}
