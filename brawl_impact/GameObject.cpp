#include "GameObject.h"
#include "TextureManager.h"
#include "Map.h"




GameObject::GameObject(const char* texturesheet, int x, int y, bool isX_const, bool isY_const)
{
	distance = 0;
	objTexture = TextureManager::LoadTexture(texturesheet); //load texture
	xpos = x;
	ypos = y;
	int step = 1;
	int coef = 1;

	srcRect.h = 120;
	srcRect.w = 120;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.w = 120;
	destRect.h = 120;

	int currentTime = 0, lastTime = 0, startTime = 0;
	vector<string > textures = {"morgenshtern/frames/frame_-4.png", "morgenshtern/frames/frame_-3.png",
	"morgenshtern/frames/frame_-2.png", "morgenshtern/frames/frame_-1.png", "morgenshtern/frames/frame_0.png",
	"morgenshtern/frames/frame_1.png", "morgenshtern/frames/frame_2.png", "morgenshtern/frames/frame_3.png",
	"morgenshtern/frames/frame_4.png" };
}

void GameObject::Update()
{
	cout << xpos << endl;
	destRect.x = xpos;
	destRect.y = ypos;
	currentTime = round(SDL_GetTicks() / 1000);
	if (xpos >= 4000)
		xpos += 3;
	else if ((!isX_const && xpos < 960)) {
		xpos += x_speed;
	}
	if (!isY_const) {
		ypos += y_speed * coef;
	}
	if (xpos > 6000 || ypos > 1080 || xpos < 0 || ypos < 0) {
		is_dead = true;
	}
	check_collision();
	if (is_dead) {
		x_speed = 0;
		y_speed = 0;

	}
}

void GameObject::check_collision() {
	cout << distance << endl;
	if (level1[ypos / 120][(xpos + distance) / 120] == 1) {
		is_dead = true;
	}
}

void GameObject::jump()
{
	if (!isY_const) {
		startTime = round(SDL_GetTicks() / 1000);
		lastTime = round(SDL_GetTicks() / 1000);
		coef *= -1;
		currentTime = startTime;
		if (isJump) {
			isJump = false;
			step = 1;
		}
		else {
			isJump = true;
			step = 2;
		}
	}
}

void GameObject::Render()
{
	if ((distance + 1920) < 6000) //map moving if not end
		distance += 3; 

	switch (step)
	{
	case 1:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_3.png");
		break;
	case 2:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_-3.png");
		break;
	}
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}