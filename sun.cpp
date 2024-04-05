#include "sun.h"
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
bool sun::spawn()
{
    srand(time(0));
    pos.x=(rand()*123)%(SCREEN_WIDTH-100);
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

