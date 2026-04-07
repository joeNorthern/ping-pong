#include <stdio.h>
#include <SDL2/SDL.h>
#include "ball.h"
#define COLOR_WHITE 255, 255, 255, 255

SDL_Rect ball = {0, 0, 5, 5};


void adjBall()
{
	ball.x = X_AXIS/2-ball.w;
	ball.y = Y_AXIS/2-ball.h;
}
void rendBall(SDL_Renderer* render)
{
	SDL_SetRenderDrawColor(render, COLOR_WHITE);
	SDL_RenderFillRect(render, &ball);
}
