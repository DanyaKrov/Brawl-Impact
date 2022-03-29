#pragma once

#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Menu.h"
#include <windows.h>
using namespace std;

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreeen);
	void handleEvevents();
	void update();
	void render();
	void clean();

	void main_menu();

	static SDL_Renderer* renderer;
	bool running() { return isRunning; };
private:
	bool inMenu = TRUE;
	int level = 0;
	int count = 0;
	bool isRunning;
	SDL_Window* window;
};