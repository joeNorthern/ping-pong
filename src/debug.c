#include "debug.h"
#include "paddles.h"

void debugPrint(uint32_t *currentFps, uint32_t *lastFps, int flags)
{
	if((SDL_GetTicks() - *lastFps) >= 1000)
	{
		putchar('\r');
		if(flags & DEBUG_FPS_ONLY) printf("FPS: %d ", *currentFps);
		if(flags & DEBUG_YAXIS_ONLY) printf("PLAYER: %d ENEMY: %d", player.y, enemy.y);
		printf("        ");
		fflush(stdout);
		*currentFps = 0;
		*lastFps = SDL_GetTicks();
	}
}


// USAGE
// This debugPrint uses flags that specify what you want to be debugged;
// either FPS, the Y axis paddle movemets, or both.
// To use it, simply refer to the declared macros in main.c
// 
// The macros should be inserted in the flag parameter.
//
// * Notice that debugPrint will disable the player scores print, since it is being replaced by the fflush call.
