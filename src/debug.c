#include "debug.h"

void fpsCheck(uint32_t *currentFps, uint32_t *lastFps)
{
	if((SDL_GetTicks() - *lastFps) >= 1000)
	{
		printf("\rFPS: %d", *currentFps);
		fflush(stdout);
		*currentFps = 0;
		*lastFps = SDL_GetTicks();
	}
}
