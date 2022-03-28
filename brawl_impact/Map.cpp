#include "Map.h"

int level1[11][20] = {
{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
Map::Map()
{
	mainText = TextureManager::LoadTexture("morgenshtern/bg_4.jpg");
	barrier = TextureManager::LoadTexture("morgenshtern/barrier_1.png");

	LoadMap(level1);

	src.x = src.y = 0;

	bar_src.x = bar_src.y = 0;

	bar_dest.x = bar_dest.y = 0;

	bar_src.h = bar_src.w = 102;

	bar_dest.h = bar_dest.w = 102;

	src.h = dest.h = 1084;
	src.w = dest.w = 2048;

	dest.x = dest.y = 0;
}
void Map::LoadMap(int arr[11][20])
{
	for (int row = 0; row < 11; row++) {
		for (int collumn = 0; collumn < 20; collumn++) {
			map[row][collumn] = arr[row][collumn];
		}
	}
}
void Map::DrawMap()
{
	TextureManager::Draw(mainText, src, dest);
	for (int row = 0; row < 11; row++) {
		for (int collumn = 0; collumn < 20; collumn++) {
			if (map[row][collumn] == 1) {
				bar_dest.x = collumn * 102;
				bar_dest.y = row * 102;
				TextureManager::Draw(barrier, bar_src, bar_dest);
			}
		}
	}
}