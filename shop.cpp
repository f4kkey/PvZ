#include "shop.h"
shop::shop()
{
    totalSun=0;
    pos={0,0,SCREEN_WIDTH,150};

}
void shop::event(SDL_Event e)
{
    for(int i=0;i<s.size();i++)
    {
        sun &tmp=s[i];
        int val=s[i].event(e);
        if(val)
        {
            totalSun+=val;
            s.erase(s.begin()+i);
            break;
        }
    }
}
void shop::spawn()
{
    if(S.spawn())
    {
        s.push_back(S);
    }
}
void shop::update()
{
    for(auto &tmp:s)
    {
        tmp.move();
    }
}
void shop::render()
{
    for(auto &tmp:s)
    {
        tmp.render();
    }
}

