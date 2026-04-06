#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdint.h>
#include "../include/paddles.h"

const int Y_AXIS = 1000;
const int X_AXIS = 1000;

int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("SDL couldn't initialize: %s\n", SDL_GetError());

	SDL_Window* window = SDL_CreateWindow(
		"Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		Y_AXIS, X_AXIS,
		0
	);

	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

	short running = 1;
	SDL_Event event;

	uint32_t lastFps = SDL_GetTicks();
	uint32_t currentFps = 0;

	const uint8_t* keys = SDL_GetKeyboardState(NULL);

	initPlayer();
	initEnemy();

	while(running)
	{
		SDL_Delay(16);

		while(SDL_PollEvent(&event))
			if(event.type == SDL_QUIT)
				running = 0;

		checkPlayerMovements(keys);

		currentFps++;
		if((SDL_GetTicks() - lastFps) >= 1000)
		{
			currentFps = 0;
			lastFps = SDL_GetTicks();	
		}
		
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);

		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		SDL_RenderFillRect(render, &player);

		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		SDL_RenderFillRect(render, &enemy);
		SDL_RenderPresent(render);
	}
	
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
