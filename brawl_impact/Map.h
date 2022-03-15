#pragma once
#include "Game.h"
#include "TextureManager.h"


class Map {
public:
	Map();
	~Map();
	void LoadMap(int arr[20][20]);
	void DrawMap();
private:
	SDL_Rect src, dest;
	SDL_Texture* ground;
	SDL_Texture* sky;
	SDL_Texture* cactus;

	int map[20][20];
};