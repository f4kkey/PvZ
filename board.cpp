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

    Z1.spawn(1);
    z1[1].push_back(Z1);
    Z1.spawn(2);
    z1[2].push_back(Z1);
    Z1.spawn(4);
    z1[4].push_back(Z1);

    P.spawn(pos[0][2].x,pos[0][2].y);
    p[2].push_back(P);
    P.spawn(pos[3][1].x,pos[3][1].y);
    p[1].push_back(P);
    P.spawn(pos[2][4].x,pos[2][4].y);
    p[4].push_back(P);
}
void board::update()
{
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:p[i])
        {
            SDL_Rect position=tmp.getPos();
            if(tmp.fire())
            {
                if(detechZombie(i,position))
               {
                    PE.spawn(position.x+position.w,position.y);
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
                    if(!t2.checkStatus())
                    {
                        z1[row].erase(z1[row].begin()+j);
                        j--;
                    }
                    break;
                }
            }
        }
    }
//    for(int row=0;row<5;row++)
//    {
//        for(int i=0;i<z1[row].size();i++)
//        {
//            for(int j=0;j<z1[row].size();j++)
//            {
//                pea &t1=pe[row][i];
//                basicZombie &t2=z1[row][j];
//            }
//        }
//    }
}
void board::render()
{
    SDL_RenderCopy(ren,tex,NULL,NULL);
    for(int i=0;i<5;i++)
    {
        for(auto &tmp:z1[i]) tmp.render();
        for(auto &tmp:pe[i]) tmp.render();
        for(auto &tmp:p[i]) tmp.render();
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

