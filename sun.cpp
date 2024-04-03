#include "sun.h"
sun::sun()
{
    value=25;
    pos={-1,0,100,100};
    fallSpeed=3;
    sunSpawnTime=preSunSpawnTime=0;
    sunSpawnSpeed=4000;
}
SDL_Rect sun::getPos()
{
    return pos;
}
bool sun::spawn()
{

    sunSpawnTime=SDL_GetTicks();

    if(sunSpawnTime-preSunSpawnTime>=sunSpawnSpeed)
    {
        preSunSpawnTime=sunSpawnTime;
        srand(time(0));
        pos.x=(rand()*123)%(SCREEN_WIDTH-100);
        endPos=(rand()*123)%(SCREEN_HEIGHT-200)+100;
        return 1;
    }
    return 0;
}
void sun::render()
{
//    cout<<pos.x<<"\n";
    SDL_RenderCopy(ren,tSun,NULL,&pos);
}
int sun::event(SDL_Event e)
{
    if(e.type==SDL_MOUSEBUTTONDOWN)
    {
        int x,y;
        SDL_GetMouseState(&x,&y);
        if(x>=pos.x&&x<=pos.x+pos.w&&y>=pos.y&&y<=pos.y+pos.h)
        {
            return value;
        }
    }
    return 0;
}
void sun::move()
{
    pos.y+=fallSpeed;
    if(pos.y>=endPos) pos.y=endPos;
}
