#include "zombie.h"
#include "board.h"
zombie::zombie()
{
    damage=50;
    v=1;
    live=1;
    val=1;
    walkInterval=65;
    preWalkTime=0;
    biteInterval=500;
    isBiting=0;
    preBiteTime=0;
    vFall=3;
    bottom={10,190};
    bodyAngle=0;

    armAngle=legAngle=0;
    vLeg=vArm=1;
    armCenter={50,60};
    pos.w=100;
    pos.h=170;
    pos.x=SCREEN_WIDTH;
    exist=1;
}
void zombie::move()
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
                    Mix_PlayChannel(-1,mSwallow,0);
                }
                legAngle=0;
                break;
            }
        }
    }
    if(SDL_GetTicks()-preWalkTime>=walkInterval)
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
                if(pos.x+pos.w<0) board::state=1;
            }
            else
            {
                if(armAngle>=10||armAngle<=-10) vArm=-vArm;
                armAngle+=vArm;
            }
        }
        else
        {
            bodyAngle=max(bodyAngle-vFall,-90);
            if(SDL_GetTicks()-deadTime>3000) exist=0;
        }
        preWalkTime=SDL_GetTicks();
    }
}
SDL_Rect zombie::getPos()
{
    return pos;
}
void zombie::spawn(int x)
{
    if(x==5)
    {
        srand(time(0));
        row=rand()%5;
    }
    else row=x;
}
void zombie::takeDamage(int damageTaken)
{
    health-=damageTaken;
    if(health<=0)
    {
        live=0;
        deadTime=SDL_GetTicks();
    }
}
bool zombie::alive()
{
    return live;
}
int zombie::bite()
{
    if(SDL_GetTicks()-preBiteTime>=biteInterval)
    {
        preBiteTime=SDL_GetTicks();
        Mix_PlayChannel(-1,mEat,0);
        return damage;
    }
    return 0;
}
void zombie::biting(bool mask)
{
    isBiting=mask;
}
bool zombie::disapear()
{
    return 1-exist;
}
