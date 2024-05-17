#include "flagZombie.h"
#include "board.h"
flagZombie::flagZombie()
{
    health=1301;
    walkInterval=20;
    biteInterval=300;
}
void flagZombie::render()
{
    if(live)
    {
        SDL_RenderCopy(ren,tBackFlagArm,NULL,&pos);
        SDL_RenderCopyEx(ren,tBackLeg,NULL,&pos,legAngle,NULL,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tFrontLeg,NULL,&pos,-legAngle,NULL,SDL_FLIP_NONE);
        SDL_RenderCopy(ren,tBody,NULL,&pos);
        SDL_RenderCopy(ren,tHead,NULL,&pos);
        if(health>90) SDL_RenderCopyEx(ren,tFrontArm,NULL,&pos,-armAngle+isBiting*50,&armCenter,SDL_FLIP_NONE);
        if(health>921) SDL_RenderCopy(ren,tBucket,NULL,&pos);
        else if(health>561) SDL_RenderCopy(ren,tBucket2,NULL,&pos);
        else if(health>181)SDL_RenderCopy(ren,tBucket3,NULL,&pos);
    }
    else
    {
        SDL_RenderCopyEx(ren,tBackLeg,NULL,&pos,bodyAngle,&bottom,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tFrontLeg,NULL,&pos,bodyAngle,&bottom,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tBody,NULL,&pos,bodyAngle,&bottom,SDL_FLIP_NONE);
    }
}
