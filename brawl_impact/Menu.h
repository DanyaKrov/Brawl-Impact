#pragma once
#include "Game.h"
#include "TextureManager.h"


class Menu {
public:
	Menu(int level);
	~Menu();

	void LoadMenu();
	void DrawMenu();
	bool Render();
	static SDL_Renderer* renderer1;
private:
	SDL_Texture* background;
	int x_mouse, y_mouse;
	SDL_Rect src, dest;

	SDL_Window* window;
};