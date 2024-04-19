#include "level.h"
levelMenu::levelMenu()
{
    join=1;
    level1={200,200,200,200};
    level2={800,200,200,200};
    quit={400,500,400,200};
    val=0;
}
void levelMenu::render()
{
    SDL_SetRenderDrawColor(ren,255,255,255,255);
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren,tLevel,NULL,NULL);
}
void levelMenu::event(SDL_Event e)
{
    if(e.type==SDL_MOUSEBUTTONDOWN)
    {
        int x,y;
        SDL_GetMouseState(&x,&y);
        if(inside(x,y,level1)) val=1;
        if(inside(x,y,level2)) val=2;
        if(inside(x,y,quit)) val=-1;
    }
}
int levelMenu::getVal()
{
    int tmp=val;
    val=0;
    return tmp;
}
