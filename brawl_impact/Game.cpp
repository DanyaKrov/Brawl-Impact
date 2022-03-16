#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* hero;
SDL_Renderer* Game::renderer = nullptr;
Map* map;
Game::Game()
{}
Game::~Game()
{}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreeen)
{
	int flags = 0;
	if (fullscreeen)
		flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {

		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	else
		isRunning = false;
	hero = new GameObject("morgenshtern/frames/frame_0.png", 0, 0); //player
	map = new Map();
}

void Game::handleEvevents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}

void Game::update()
{
	count++;
	if (GetKeyState(VK_SPACE) & 0x8000)
		hero->jump();
	hero->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	hero->Render();
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}