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
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,8,2048);
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
    SDL_SetTextureAlphaMod(tBlank,127);
    tFinalWave=loadIMG("resources/others/finalwave.png");
    tLevel=loadIMG("resources/others/levelmenu.png");
    tLose=loadIMG("resources/others/lose.png");
    tWin=loadIMG("resources/others/win.png");

    tPlant[0]=loadIMG("resources/plants/peashooter.png");
    tPlant[1]=loadIMG("resources/plants/sunflower.png");
    tPlant[2]=loadIMG("resources/plants/wallnut.png");
    tPlant[3]=loadIMG("resources/plants/cherrybomb.png");
    tPlant[4]=loadIMG("resources/plants/potatomine.png");
    tPlant[5]=loadIMG("resources/plants/repeater.png");

    tHead=loadIMG("resources/zombies/head.png");
    tBody=loadIMG("resources/zombies/body.png");
    tBackLeg=loadIMG("resources/zombies/backleg.png");
    tFrontLeg=loadIMG("resources/zombies/frontleg.png");
    tBackArm=loadIMG("resources/zombies/backarm.png");
    tBackFlagArm=loadIMG("resources/zombies/backflagarm.png");
    tFrontArm=loadIMG("resources/zombies/frontarm.png");
    tCone=loadIMG("resources/zombies/cone.png");
    tCone2=loadIMG("resources/zombies/cone2.png");
    tCone3=loadIMG("resources/zombies/cone3.png");
    tBucket=loadIMG("resources/zombies/bucket.png");
    tBucket2=loadIMG("resources/zombies/bucket2.png");
    tBucket3=loadIMG("resources/zombies/bucket3.png");

    mEat=Mix_LoadWAV("resources/sounds/eatSound.ogg");
    mSwallow=Mix_LoadWAV("resources/sounds/swallowSound.ogg");
    mPlant=Mix_LoadWAV("resources/sounds/plantSound.ogg");
    mSplat=Mix_LoadWAV("resources/sounds/splatSound.ogg");
    mSun=Mix_LoadWAV("resources/sounds/sunPickedSound.ogg");
    mPotatoMine=Mix_LoadWAV("resources/sounds/potatomine.ogg");
    mCherryBomb=Mix_LoadWAV("resources/sounds/cherrybomb.ogg");
    mFirstWave=Mix_LoadWAV("resources/sounds/firstWave.mp3");
    mSeedPacket=Mix_LoadWAV("resources/sounds/seedPacket.mp3");
    mWave=Mix_LoadWAV("resources/sounds/wave.mp3");
    mInGame=Mix_LoadMUS("resources/sounds/ingame.ogg");
    mMenu=Mix_LoadMUS("resources/sounds/menu.ogg");
    mLose=Mix_LoadMUS("resources/sounds/lose.ogg");
    mWin=Mix_LoadMUS("resources/sounds/win.ogg");
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
            if(ingame)
            {
                Mix_HaltMusic();
                Mix_PlayMusic(mInGame,-1);
                b.reset();
            }
        }
        else
        {
            if(!b.endGame())
            {
                if(e.type==SDL_MOUSEBUTTONDOWN)
                {
                    int x,y;
                    SDL_GetMouseState(&x,&y);
                    if(x>=SCREEN_WIDTH-240&&x<=SCREEN_WIDTH&&y<=150&&y>=0)
                    {
                        ingame=0;
                        Mix_HaltMusic();
                        Mix_PlayMusic(mMenu,-1);
                    }
                    b.event(e);
                }
            }
            else
            {
                if(e.type==SDL_MOUSEBUTTONDOWN)
                {
                    ingame=0;
                    Mix_HaltMusic();
                    Mix_PlayMusic(mMenu,-1);
                }
            }

        }

    }
    if(!b.endGame()&&ingame)
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
        if(!b.endGame()) b.render();
        else if(b.endGame()==1)
        {
            SDL_RenderCopy(ren,tLose,NULL,NULL);
        }
        else
        {
            SDL_RenderCopy(ren,tWin,NULL,NULL);
        }

    }
    SDL_RenderPresent(ren);
}
