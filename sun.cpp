#include "sun.h"
#include "shop.h"
sun::sun()
{
    value=25;
    pos={-1,0,100,100};
    fallSpeed=3;

    endTime=curTime=0;;
    duration=5000;
    live=1;
}
SDL_Rect sun::getPos()
{
    return pos;
}
void sun::spawn(int x,int y,int range)
{
    srand(time(0));
    if(y==-1)
    {
        pos.x=(rand()*123)%(SCREEN_WIDTH-400);
        pos.y=-pos.h;
    }
    else
    {
        pos.x=x+(rand()%range);
        pos.y=y;
    }
    endPos=(rand()*123)%(SCREEN_HEIGHT-200)+100;
}
void sun::render()
{
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
            live=0;
            Mix_PlayChannel(-1,mSun,0);
            return value;
        }
    }
    return 0;
}
void sun::move()
{
    pos.y+=fallSpeed;
    if(pos.y>=endPos)
    {
        pos.y=endPos;
        if(!endTime) endTime=SDL_GetTicks();
        else curTime=SDL_GetTicks();
    }
    if(curTime-endTime>=duration) live=0;
}
bool sun::alive()
{
    return live;
}
void sun::setEndPos(int y)
{
    endPos=y;
}
