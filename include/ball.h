#ifndef BALL_H
#define BALL_H

#include <stdio.h>
#include <SDL2/SDL.h>

extern SDL_Rect player;
extern SDL_Rect enemy;
extern const int Y_AXIS;
extern const int X_AXIS;

void adjBall(void);
void rendBall(SDL_Renderer *);
void ballMove(void);
void ballCollide(void);
void scoreShow(void);

#endif
