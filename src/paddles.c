#include "paddles.h"
#define DEBUG 0

//testing this rn

SDL_Rect player = {20, 80, 10, 80}; // x, y, w, h
SDL_Rect enemy = {970, 80, 10, 80}; // x, y, w, h

void initPlayer()
{
	player.y = Y_AXIS/2-player.h;
}

void initEnemy()
{
	enemy.y = Y_AXIS/2-enemy.h;
}

void checkPlayerMovements(const uint8_t* keys)
{
	if(keys[SDL_SCANCODE_W] && player.y > 0) player.y -= 10;
	if(keys[SDL_SCANCODE_S] && player.y < Y_AXIS - player.h) player.y += 10;
	#ifdef DEBUG
		printf("\rPLAYER_Y: %d ENEMY_Y %d", player.y, enemy.y);
		fflush(stdout);
	#endif
}
