#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include "../include/paddles.h"
#include "../include/ball.h"
#include "../include/debug.h"
// #define DEBUG 0

const int Y_AXIS = 1000;
const int X_AXIS = 1000;

extern short playerScore;
extern short enemyScore;

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
	short BALL_GO_UP = 1;

	adjPlayer(); // adjust player starting pos
	adjEnemy(); // adjust enemy starting pos
	adjBall(); // adjust ball starting pos

	while(running)
	{
		SDL_Delay(16);

		while(SDL_PollEvent(&event))
			if(event.type == SDL_QUIT)
				running = 0;

		checkPlayerMovements(keys);
		checkEnemyMovements(keys);
		
		ballMove();

		ballCollide();

		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);
		
		scoreShow();

		rendPlayer(render);
		rendEnemy(render);
		rendBall(render);
		
		#ifdef DEBUG
			++currentFps;
			debugPrint(&currentFps, &lastFps, DEBUG_ALL);
		#endif
		#ifndef DEBUG
			printf("\rPLAYER: %d ENEMY: %d", playerScore, enemyScore);
			fflush(stdout);
		#endif
		SDL_RenderPresent(render);
	}
	
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
