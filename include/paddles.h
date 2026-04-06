#ifndef PADDLES_H
#define PADDLES_H

#include <stdio.h>
#include <SDL2/SDL.h>

extern SDL_Rect player;
extern SDL_Rect enemy;
extern const int Y_AXIS;
extern const int X_AXIS;

void initPlayer(); // simply corrects starting Y axis
void initEnemy(); // same as above, for enemy
void checkPlayerMovements(const uint8_t*);

#endif
