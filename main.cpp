#include "game.h"
using namespace std;
game G;
int main(int agrv,char *argc[])
{

    G.init();
    G.loadResources();
    while(G.getGameState())
    {
        G.event();
        G.render();
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(ren);
    return 0;

}
