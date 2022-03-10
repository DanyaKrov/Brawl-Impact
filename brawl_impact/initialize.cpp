#include "game.h"

bool initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    return true;
}