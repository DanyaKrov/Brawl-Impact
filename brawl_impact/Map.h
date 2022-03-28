#pragma once
#include "Game.h"
#include "TextureManager.h"


class Map {
public:
	Map();
	void LoadMap(int arr[11][20]);
	void DrawMap();
private:
	SDL_Rect src, dest, bar_src, bar_dest;
	SDL_Texture* mainText;
	SDL_Texture* barrier;

	int map[20][20];
};