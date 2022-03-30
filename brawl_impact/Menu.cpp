#include "Menu.h"

Menu::Menu()
{
	background = TextureManager::LoadTexture("menus/main_menu.png");

	dest.x = dest.y = src.x = src.y = 0;

	src.h = dest.h = 1080;
	src.w = dest.w = 1920;

}
void Menu::DrawMenu()
{
	ShowCursor(TRUE);
	TextureManager::Draw(background, src, dest);
}
bool Menu::Click(int xpos, int ypos)
{
	if (start[0] <= xpos && xpos <= start[2] && start[1] <= ypos && ypos <= start[3]) {
		ShowCursor(FALSE);
		return false;
	}
	if (settings[0] <= xpos && xpos <= settings[2] && settings[1] <= ypos && ypos <= settings[3]) {
		return true;
	}
	if (exit[0] <= xpos && xpos <= exit[2] && exit[1] <= ypos && ypos <= exit[3]) {
		SDL_DestroyRenderer(Game::renderer);
		Mix_CloseAudio();
		SDL_Quit();
		std::exit(0);
	}
	return true;
}