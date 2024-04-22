#include "basicZombie.h"
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
void coneZombie::move()
{
    if(live)
    {
        isBiting=0;
        for(int j=0;j<board::p[row].size();j++)
        {
            plant *tmp=board::p[row][j];
            if(collision(pos,tmp->getPos()))
            {
                isBiting=1;
                tmp->takeDamage(bite());
                if(!tmp->alive())
                {
                    board::exist[tmp->getColumn()][row]=0;
                    delete tmp;
                    board::p[row].erase(board::p[row].begin()+j);
                    isBiting=0;
                }
                legAngle=0;
                break;
            }
        }
    }
    walkTime=SDL_GetTicks();
    if(walkTime-preWalkTime>=walkSpeed)
    {
        if(live)
        {
            if(!isBiting)
            {
                if(legAngle>=10||legAngle<=-10) vLeg=-vLeg;
                legAngle+=vLeg;
                if(armAngle>=10||armAngle<=-10) vArm=-vArm;
                armAngle+=vArm;
                pos.y=board::pos[0][row].y+TILE_HEIGHT-pos.h;
                pos.x-=v;
            }
            else
            {
                if(armAngle>=10||armAngle<=-10) vArm=-vArm;
                armAngle+=vArm;
                preWalkTime=walkTime;
            }
        }
        else
        {
            bodyAngle=max(bodyAngle-vFall,-90);
            if(SDL_GetTicks()-deadTime>3000) exist=0;
        }
        preWalkTime=walkTime;
    }
}
