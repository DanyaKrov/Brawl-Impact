#pragma once
#include "Game.h"

class GameObject {
public:
	GameObject(const char* texturesheet, int x, int y, bool isX_const, bool isY_const);
	~GameObject();
	
	void Update();
	void Render();
	void jump();
private:
	int xpos, ypos;
	bool isX_const, isY_const;
	bool isFall = true;
	bool isJump = false;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

	vector<string*> textures;

	int currentTime, lastTime, startTime;
	int step, count;

	//some physics
	int speed = 1.5;
	int time;
	int boost = 1;
};