#pragma once
#include "Game.h"
#include "TextureManager.h"


class Map {
public:
	Map();
	void LoadMap(int arr[9][50]);
	void DrawMap();
private:
	SDL_Rect src, dest, bar_src, bar_dest;
	SDL_Texture* mainText;
	SDL_Texture* barrier;

	int map[9][50];
};