#include "paddles.h"
#define COLOR_WHITE 255, 255, 255, 255
#define SPEED 15

SDL_Rect player = {20, 0, 10, 120}; // x, y, w, h
SDL_Rect enemy = {970, 0, 10, 120}; // x, y, w, h
SDL_Rect separatingLine = {0,0,0,0}; // x, y, w, h

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

void checkPlayerMovements(const uint8_t* keys)
{
	if(keys[SDL_SCANCODE_W] && player.y > 0) player.y -= SPEED;
	if(keys[SDL_SCANCODE_S] && player.y < Y_AXIS - player.h) player.y += SPEED;
}

void checkEnemyMovements(const uint8_t* keys)
{
	if(keys[SDL_SCANCODE_UP] && enemy.y > 0) enemy.y -= SPEED;
	if(keys[SDL_SCANCODE_DOWN] && enemy.y < Y_AXIS - enemy.h) enemy.y += SPEED;
}
