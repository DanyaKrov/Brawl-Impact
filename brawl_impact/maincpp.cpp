#include "game.h"

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

int main(int argc, char* args[])
{
    bool quit = false;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL2 Displaying Image",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* image = IMG_Load("1.png");
    if (!image) {
        cout << "Can't load image!";
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    if(!texture)
        cout << "Can't load texture";
    SDL_Rect rectangle;
    SDL_Rect* rectanglePointer = &rectangle;
    rectangle.w = 150;
    rectangle.h = 150;
    rectangle.y = 0;
    rectangle.x = 0;
    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, rectanglePointer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}