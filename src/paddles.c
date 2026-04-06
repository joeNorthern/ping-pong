#include <stdio.h>
#include <SDL2/SDL.h>

//testing this rn

extern int Y_AXIS;
extern int X_AXIS;

SDL_Rect player;
player.w = 10;
player.h = 80;
player.x = 20;
player.y = Y_AXIS/2-80;

void checkPlayerMovements(uint8_t* keys)
{
	if(keys[SDL_SCANCODE_W] && player.y >= 0)                player.y -= 10;
	if(keys[SDL_SCANCODE_S] && player.y <= Y_AXIS - player.h) player.y += 10;
}
