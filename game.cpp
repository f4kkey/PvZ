#include "game.h"
game::game()
{
    gameState=1;
    time=pretime=0;
}
void game::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window=SDL_CreateWindow("PvZ",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
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

    tBasicZombie=loadIMG("resources/zombies/basic.png");

    tPeashooter=loadIMG("resources/plants/peashooter.png");
    tSunFlower=loadIMG("resources/plants/sunflower.png");
    tWallnut=loadIMG("resources/plants/wallnut.png");
    tCherryBomb=loadIMG("resources/plants/cherrybomb.png");
}
void game::event()
{
    time=SDL_GetTicks();
    if(time-pretime<=20)
    {
        SDL_Delay(20-(time-pretime));
        pretime=time;
    }
    time=SDL_GetTicks();
    if(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT) gameState=0;
        b.event(e);
    }
    b.spawnSun();
    b.update();
}
bool game::getGameState()
{
    return gameState;
}
void game::render()
{
    b.render();
    SDL_RenderPresent(ren);
}
void game::setup()
{
    b.start();
}
