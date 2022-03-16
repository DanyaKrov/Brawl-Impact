#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y, bool isX_const, bool isY_const)
{
	objTexture = TextureManager::LoadTexture(texturesheet); //load texture
	xpos = x;
	ypos = y;
	int currentTime = 0, lastTime;
	vector<string > textures = {"morgenshtern/frames/frame_-4.png", "morgenshtern/frames/frame_-3.png",
	"morgenshtern/frames/frame_-2.png", "morgenshtern/frames/frame_-1.png", "morgenshtern/frames/frame_0.png",
	"morgenshtern/frames/frame_1.png", "morgenshtern/frames/frame_2.png", "morgenshtern/frames/frame_3.png",
	"morgenshtern/frames/frame_4.png" };
}
void GameObject::Update()
{
	if (!isX_const)
		xpos++;
	if (!isY_const && isFall)
		ypos++;
	srcRect.h = 120;
	srcRect.w = 120;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 120;
	destRect.h = 120;
}
void GameObject::jump()
{
	if (!isY_const && isFall) {
		currentTime = SDL_GetTicks();
		ypos -= 16;
		isFall = false;
		isJump = true;
	}
}

void GameObject::Render()
{
	currentTime = SDL_GetTicks();
	if (isJump) {
		switch (int((currentTime - lastTime) / 1000))
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
			isJump = false;
			isFall = true;
			lastTime = SDL_GetTicks();
			break;
		}
	}
	if (isFall) {
		switch (int((currentTime - lastTime) / 1000))
		{
		case 0:
			objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_0.png");
			break;
		case 1:
			objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_1.png");
			break;
		case 2:
			objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_2.png");
			break;
		case 3:
			objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_3.png");
			break;
		case 4:
			objTexture = TextureManager::LoadTexture("morgenshtern/frames/frame_4.png");
			break;
		}
	}
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}