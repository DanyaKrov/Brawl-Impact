#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* hero;
SDL_Renderer* Game::renderer = nullptr;
Map* map;
Menu* menu;
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
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	else
		isRunning = false;
	hero = new GameObject("morgenshtern/frames/frame_0.png", 0, 0, false, false); //player
	map = new Map();
	menu = new Menu();
}

void Game::handleEvevents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_SPACE:
			hero->jump();
			break;
		case SDLK_r:
			hero->restart();
			break;
		}
	}
	if (inMenu && event.type == SDL_MOUSEBUTTONDOWN) 
		inMenu = menu->Click(event.motion.x, event.motion.y);
}

void Game::update() 
{
	if (!inMenu) {
		count++;
		hero->Update();
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	if (inMenu) {
		menu->DrawMenu();
	}
	else {
		map->DrawMap();
		hero->Render();
	}
	SDL_RenderPresent(renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_CloseAudio();
	SDL_Quit();
	cout << "Game cleaned" << endl;
}