#ifndef DEBUG_H
#define DEBUG_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>

extern float hitPos;
extern SDL_Rect ball;

#define DEBUG_FPS_ONLY   1
#define DEBUG_YAXIS_ONLY 2
#define DEBUG_BALL_HITPOS 3
#define DEBUG_ALL   DEBUG_FPS_ONLY | DEBUG_YAXIS_ONLY | DEBUG_BALL_HITPOS

void debugPrint(uint32_t *, uint32_t *, int);
void getFps(uint32_t *, uint32_t *);

#endif
