#include "game.h"
int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Unable to init SDL: %s", SDL_GetError());
        return 1;
    }
    return 0;
}