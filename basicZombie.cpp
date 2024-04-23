#include "basicZombie.h"
#include "board.h"
basicZombie::basicZombie()
{
    health=181;
}
void basicZombie::render()
{
    if(live)
    {
        SDL_RenderCopyEx(ren,tBackArm,NULL,&pos,armAngle+isBiting*50,&armCenter,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tBackLeg,NULL,&pos,legAngle,NULL,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tFrontLeg,NULL,&pos,-legAngle,NULL,SDL_FLIP_NONE);
        SDL_RenderCopy(ren,tBody,NULL,&pos);
        SDL_RenderCopy(ren,tHead,NULL,&pos);
        if(health>90) SDL_RenderCopyEx(ren,tFrontArm,NULL,&pos,-armAngle+isBiting*50,&armCenter,SDL_FLIP_NONE);
    }
    else
    {
        SDL_RenderCopyEx(ren,tBackLeg,NULL,&pos,bodyAngle,&bottom,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tFrontLeg,NULL,&pos,bodyAngle,&bottom,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tBody,NULL,&pos,bodyAngle,&bottom,SDL_FLIP_NONE);
    }
}
