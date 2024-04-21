#include "bucketZombie.h"
#include "board.h"
bucketZombie::bucketZombie()
{
    health=1281;
}
void bucketZombie::render()
{
    SDL_RenderCopyEx(ren,tBackHand,NULL,&pos,handAngle+isBiting*50,&handCenter,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren,tBackLeg,NULL,&pos,legAngle,NULL,SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren,tFrontLeg,NULL,&pos,-legAngle,NULL,SDL_FLIP_NONE);
    SDL_RenderCopy(ren,tBody,NULL,&pos);
    if(health>90) SDL_RenderCopyEx(ren,tFrontHand,NULL,&pos,-handAngle+isBiting*50,&handCenter,SDL_FLIP_NONE);
    if(health>921) SDL_RenderCopy(ren,tBucket,NULL,&pos);
    else if(health>561) SDL_RenderCopy(ren,tBucket2,NULL,&pos);
    else if(health>181)
    {
//        cout<<"lmao\n";
        SDL_RenderCopy(ren,tBucket3,NULL,&pos);
    }
}
void bucketZombie::move()
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
        }
    }
    walkTime=SDL_GetTicks();
    if(walkTime-preWalkTime>=walkSpeed)
    {
        if(!isBiting)
        {
            if(legAngle>=10||legAngle<=-10) vLeg=-vLeg;
            legAngle+=vLeg;
            if(handAngle>=10||handAngle<=-10) vHand=-vHand;
            handAngle+=vHand;
            pos.y=board::pos[0][row].y+TILE_HEIGHT-pos.h;
            pos.x-=v;
        }
        else
        {
            if(handAngle>=10||handAngle<=-10) vHand=-vHand;
            handAngle+=vHand;
            preWalkTime=walkTime;
        }
        preWalkTime=walkTime;
    }
}
