#include "Menu.h"

SDL_Renderer* Menu::renderer1 = nullptr;
Menu::Menu(int level)
{
	window = SDL_CreateWindow("Main menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 2048, 1084, false);
	renderer1 = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer1, 255, 255, 255, 255);


	src.x = src.y = 0;
	dest.x = dest.y = 0;
	src.h = dest.h = 1084;
	src.w = dest.w = 2048;
	switch (level)
	{
	case 0:
		background = TextureManager::LoadTexture("menus/main_menu.png");
	case 1:
		background = TextureManager::LoadTexture("menus/morgen_menu.jpg");
	case 2:
		background = TextureManager::LoadTexture("menus/ussr_menu.png");
	}
}
void Menu::LoadMenu() {

}
bool Menu::Render() {
	return false;
}
void Menu::DrawMenu() {
	SDL_RenderCopy(renderer1, background, NULL, NULL);
}
