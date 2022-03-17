#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y, bool isX_const, bool isY_const)
{
	objTexture = TextureManager::LoadTexture(texturesheet); //load texture
	xpos = x;
	ypos = y;
	int step = 0;
	int count = 0;



	int currentTime = 0, lastTime = 0, startTime = 0;
	vector<string > textures = {"morgenshtern/frames/frame_-4.png", "morgenshtern/frames/frame_-3.png",
	"morgenshtern/frames/frame_-2.png", "morgenshtern/frames/frame_-1.png", "morgenshtern/frames/frame_0.png",
	"morgenshtern/frames/frame_1.png", "morgenshtern/frames/frame_2.png", "morgenshtern/frames/frame_3.png",
	"morgenshtern/frames/frame_4.png" };
}
void GameObject::Update()
{
	currentTime = round(SDL_GetTicks() / 1000);
	if (!isX_const)
		xpos++;
	if (!isY_const && isFall)
		ypos += boost * (currentTime - startTime);
	srcRect.h = 120;
	srcRect.w = 120;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 120;
	destRect.h = 120;
	if (isFall) {
		if (step > -4) {
			if (currentTime - lastTime == 1) {
				lastTime = round(SDL_GetTicks() / 1000);
				step--;
			}
		}
	}
	else if (isJump) {
		ypos -= sin(60 * 3.14 / 180.0) * speed;
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
}
void GameObject::jump()
{
	if (!isY_const && isFall) {
		startTime = round(SDL_GetTicks() / 1000);
		lastTime = round(SDL_GetTicks() / 1000);
		ypos -= 4;
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