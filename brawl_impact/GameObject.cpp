#include "GameObject.h"
#include "TextureManager.h"
#include "Map.h"




GameObject::GameObject(const char* texturesheet, int x, int y, bool isX_const, bool isY_const)
{
	objTexture = TextureManager::LoadTexture(texturesheet); //load texture
	xpos = x;
	ypos = y;
	int step = 0;
	int count = 0;

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
	destRect.x = xpos;
	destRect.y = ypos;
	currentTime = round(SDL_GetTicks() / 1000);
	if (!isX_const)
		xpos += 3;
	if (!isY_const && isFall)
		ypos += 5 * coef;
	if (isFall) {
		if (step > -4) {
			if (currentTime - lastTime == 1) {
				lastTime = round(SDL_GetTicks() / 1000);
				step--;
			}
		}
	}
	else if (isJump) {
		if (currentTime - lastTime == 1) {
			lastTime = round(SDL_GetTicks() / 1000);
			step--;
			count++;
		}
		if (count == 2) {
			count = 0;
			isJump = false;
			isFall = true;
			step = -2;
		}

	}
	if (xpos > 2080 || ypos > 1084 || xpos < 0 || ypos < 0) {
		xpos = 0;
		ypos = 0;
		isFall = true;
		isJump = false;
		step = 0;
		count = 0;
	}
	check_collision();
}
void GameObject::check_collision() {
	if (level1[ypos / 102][(xpos + 102) / 102] == 1 or
		level1[(ypos + 102) / 102][xpos / 102] == 1 or
		level1[(ypos + 102) / 102][(xpos + 102) / 102] == 1 or
		level1[(ypos - 102) / 102][xpos / 102] == 1) {
		xpos = 0;
		ypos = 0;
	}

}
void GameObject::jump()
{
	if (!isY_const && isFall) {
		startTime = round(SDL_GetTicks() / 1000);
		lastTime = round(SDL_GetTicks() / 1000);
		coef *= -1;
		currentTime = startTime;
		isFall = false;
		isJump = true;
		step = 4;
	}
}

void GameObject::Render()
{
	switch (step)
	{
	case 0:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_0.png");
		break;
	case 1:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_-1.png");
		break;
	case 2:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_-2.png");
		break;
	case 3:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_-3.png");
		break;
	case 4:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_-4.png");
		break;
	case -1:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_1.png");
		break;
	case -2:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_2.png");
		break;
	case -3:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_3.png");
		break;
	case -4:
		objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_4.png");
		break;
	}
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}