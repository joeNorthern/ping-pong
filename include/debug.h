#ifndef DEBUG_H
#define DEBUG_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>

#define DEBUG_FPS_ONLY   1
#define DEBUG_YAXIS_ONLY 2
#define DEBUG_ALL   DEBUG_FPS_ONLY | DEBUG_YAXIS_ONLY

void debugPrint(uint32_t *, uint32_t *, int);

#endif
