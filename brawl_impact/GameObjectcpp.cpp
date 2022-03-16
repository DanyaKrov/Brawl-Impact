#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet); //load texture
	xpos = x;
	ypos = y;
}
void GameObject::Update()
{
	xpos++;
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
	ypos -= 16;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}