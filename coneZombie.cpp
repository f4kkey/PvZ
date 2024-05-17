#include "coneZombie.h"
#include "board.h"
coneZombie::coneZombie()
{
    health=551;
}
void coneZombie::render()
{
//    cout<<handAngle<<" "<<vHand<<"\n";
    if(live)
    {
        SDL_RenderCopyEx(ren,tBackArm,NULL,&pos,armAngle+isBiting*50,&armCenter,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tBackLeg,NULL,&pos,legAngle,NULL,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tFrontLeg,NULL,&pos,-legAngle,NULL,SDL_FLIP_NONE);
        SDL_RenderCopy(ren,tBody,NULL,&pos);
        SDL_RenderCopy(ren,tHead,NULL,&pos);
        if(health>90) SDL_RenderCopyEx(ren,tFrontArm,NULL,&pos,-armAngle+isBiting*50,&armCenter,SDL_FLIP_NONE);
        if(health>411) SDL_RenderCopy(ren,tCone,NULL,&pos);
        else if(health>291) SDL_RenderCopy(ren,tCone2,NULL,&pos);
        else if(health>181) SDL_RenderCopy(ren,tCone3,NULL,&pos);
    }
    else
    {

        SDL_RenderCopyEx(ren,tBackLeg,NULL,&pos,bodyAngle,&bottom,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tFrontLeg,NULL,&pos,bodyAngle,&bottom,SDL_FLIP_NONE);
        SDL_RenderCopyEx(ren,tBody,NULL,&pos,bodyAngle,&bottom,SDL_FLIP_NONE);
    }
}
