#include "paddles.h"
#define COLOR_WHITE 255, 255, 255, 255

//testing this rn

SDL_Rect player = {20, 0, 10, 80}; // x, y, w, h
SDL_Rect enemy = {970, 0, 10, 80}; // x, y, w, h

void adjPlayer()
{
	player.y = Y_AXIS/2-player.h;
}

void adjEnemy()
{
	enemy.y = Y_AXIS/2-enemy.h;
}

void rendPlayer(SDL_Renderer* render)
{
	SDL_SetRenderDrawColor(render, COLOR_WHITE);
	SDL_RenderFillRect(render, &player);
}

void rendEnemy(SDL_Renderer* render)
{
	SDL_SetRenderDrawColor(render, COLOR_WHITE);
	SDL_RenderFillRect(render, &enemy);
}

void enemyMoving(short *GO_UP)
{
	if(*GO_UP)
	{
		enemy.y -= 5;
		if(enemy.y <= 0) *GO_UP = 0;
	}
	else
	{
		enemy.y += 5;
		if(enemy.y >= Y_AXIS - enemy.h) *GO_UP = 1;
	}
}

void checkPlayerMovements(const uint8_t* keys)
{
	if(keys[SDL_SCANCODE_W] && player.y > 0) player.y -= 10;
	if(keys[SDL_SCANCODE_S] && player.y < Y_AXIS - player.h) player.y += 10;
}
