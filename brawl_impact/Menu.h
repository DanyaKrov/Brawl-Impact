#pragma once
#include "Game.h"
#include "TextureManager.h"


class Menu {
public:
	Menu();
	void DrawMenu();
	bool Click(int xpos, int ypos);
private:
	SDL_Rect src, dest;

	SDL_Texture* background;
	int start[4] = { 1417, 255, 1849, 334 };
	int settings[4] = { 1252, 431, 1881, 503 };
	int exit[4] = { 1437, 622, 1766, 688 };
};