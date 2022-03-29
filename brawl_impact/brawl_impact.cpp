#include "Game.h"

Game* game = nullptr;
int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frametime;
	game = new Game();
	game->init("Brawl-Impact", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, false);

	//music
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	srand(time(0));
	Mix_Music* music[] = { Mix_LoadMUS("music/caddilac.wav"), Mix_LoadMUS("music/tchaikovsky_piano_concerto_1.wav"),
	Mix_LoadMUS("music/never_gonna.wav"), Mix_LoadMUS("music/menu1.wav") };
	int index = rand() % 4;
	Mix_PlayMusic(music[index], -1);

	while (game->running()) {
		frameStart = SDL_GetTicks();
		game->handleEvevents();
		game->update();
		game->render();
		frametime = SDL_GetTicks() - frameStart;
		if (frameDelay > frametime) { //limiting frames rate
			SDL_Delay(frameDelay - frametime);
		}
	}
	game->clean();
	return 0;
}