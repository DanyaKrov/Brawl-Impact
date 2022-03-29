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



	//music
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	srand(time(0));
	Mix_Music* music[] = { Mix_LoadMUS("music/caddilac.wav"), Mix_LoadMUS("music/tchaikovsky_piano_concerto_1.wav"),
	Mix_LoadMUS("music/never_gonna.wav") };
	Mix_PlayMusic(music[rand() % 3], -1);
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
	if (!inMenu && GetKeyState(VK_SPACE) & 0x8000)
		hero->jump();
	if (inMenu && event.type == SDL_MOUSEBUTTONDOWN) {
		inMenu = menu->Click(event.motion.x, event.motion.y);
	}
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
	exit(0);
}