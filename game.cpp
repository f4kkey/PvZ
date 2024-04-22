#include "game.h"
game::game()
{
    gameState=1;
    time=pretime=0;
    ingame=0;
    restart=0;
}
void game::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window=SDL_CreateWindow("PvZ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
//    SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
    ren=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    TTF_Init();
}
void game::loadResources()
{
    font=TTF_OpenFont("resources/others/font.ttf",25);
    b.loadTexture("resources/others/background.png");
    tSun=loadIMG("resources/others/sun.png");
    tShovel=loadIMG("resources/others/shovel.png");
    tLawnmover=loadIMG("resources/others/lawnmover.png");
    tPea=loadIMG("resources/others/pea.png");
    tBlank=loadIMG("resources/others/blank.png");
    SDL_SetTextureBlendMode(tBlank,SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(tBlank,127);
    tFinalWave=loadIMG("resources/others/finalwave.png");
    tLevel=loadIMG("resources/others/levelmenu.png");

    tPeashooter=loadIMG("resources/plants/peashooter.png");
    tSunFlower=loadIMG("resources/plants/sunflower.png");
    tWallnut=loadIMG("resources/plants/wallnut.png");
    tCherryBomb=loadIMG("resources/plants/cherrybomb.png");
    tPotatoMine=loadIMG("resources/plants/potatomine.png");
    tRepeater=loadIMG("resources/plants/repeater.png");

    tHead=loadIMG("resources/zombies/head.png");
    tBody=loadIMG("resources/zombies/body.png");
    tBackLeg=loadIMG("resources/zombies/backleg.png");
    tFrontLeg=loadIMG("resources/zombies/frontleg.png");
    tBackArm=loadIMG("resources/zombies/backarm.png");
    tFrontArm=loadIMG("resources/zombies/frontarm.png");
    tCone=loadIMG("resources/zombies/cone.png");
    tCone2=loadIMG("resources/zombies/cone2.png");
    tCone3=loadIMG("resources/zombies/cone3.png");
    tBucket=loadIMG("resources/zombies/bucket.png");
    tBucket2=loadIMG("resources/zombies/bucket2.png");
    tBucket3=loadIMG("resources/zombies/bucket3.png");
}
void game::event()
{
//    ingame=1;
    time=SDL_GetTicks();
    if(time-pretime<=20)
    {
        SDL_Delay(20-(time-pretime));
        pretime=time;
    }
    time=SDL_GetTicks();
    if(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT||ingame==-1) gameState=0;
        if(!ingame)
        {
            lv.event(e);
            ingame=lv.getVal();
            if(ingame) b.reset();
        }
        else
        {
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                int x,y;
                SDL_GetMouseState(&x,&y);
                if(x>=SCREEN_WIDTH-240&&x<=SCREEN_WIDTH&&y<=100&&y>=0)
                {
                    ingame=0;
                }
                b.event(e);
            }
        }

    }
    if(ingame>0)
    {
        b.levelProgess(ingame-1);
        b.update();
    }

}
bool game::getGameState()
{
    return gameState;
}
void game::render()
{
    if(!ingame)
    {
        lv.render();
    }
    else
    {
        b.render();
    }
    SDL_RenderPresent(ren);
}
