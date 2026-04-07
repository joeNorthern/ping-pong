#ifndef PADDLES_H
#define PADDLES_H

#include <stdio.h>
#include <SDL2/SDL.h>

extern SDL_Rect player;
extern SDL_Rect enemy;
extern const int Y_AXIS;
extern const int X_AXIS;

void adjPlayer(void);
void adjEnemy(void);
void rendPlayer(SDL_Renderer *); 
void rendEnemy(SDL_Renderer *);
void enemyMoving(short *);
void checkPlayerMovements(const uint8_t *);
void checkEnemyMovements(const uint8_t *);

#endif
