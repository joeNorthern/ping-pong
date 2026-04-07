#include <stdio.h>
#include <SDL2/SDL.h>
#include "ball.h"
#include "paddles.h"
#define COLOR_WHITE 255, 255, 255, 255
#define REDUCEPOWER 50

SDL_Rect ball = {0, 0, 10, 10};

int ballVY;
int ballVX;
short playerScore = 0;
short enemyScore = 0;

void adjBall()
{
	ball.y = Y_AXIS/2-ball.h;
	ball.x = X_AXIS/2-ball.w;

	ballVY = (rand() % 2 == 0) ? 5 : -5 ;
	ballVX = (rand() % 2 == 0) ? 5 : -5 ;
}
void rendBall(SDL_Renderer* render)
{
	SDL_SetRenderDrawColor(render, COLOR_WHITE);
	SDL_RenderFillRect(render, &ball);
}

void ballMove()
{
	ball.x += ballVX;
	ball.y += ballVY;

	if(ball.y <= 0 || ball.y >= Y_AXIS - ball.h) ballVY = -ballVY;
	if(ball.x <= 0 || ball.x >= X_AXIS - ball.w) ballVX = -ballVX;
}

void scoreShow()
{
	if(ball.x >= X_AXIS - ball.w)
	{
		++playerScore;
		adjBall();
	}
	if(ball.x <= 0)
	{
		++enemyScore;
		adjBall();
	}
}

void ballCollide()
{
	if(SDL_HasIntersection(&ball, &player))
	{
		int hitPos = (player.y + (player.h/2) - ball.y);
		
		if(hitPos > 0)
		{
			ballVY += hitPos/REDUCEPOWER;
		} else
		{

			ballVY -= hitPos/REDUCEPOWER;
		}

		ballVX = -ballVX;
	} else if(SDL_HasIntersection(&ball, &enemy))
	{
		int hitPos = (enemy.y + (enemy.h/2) - enemy.y);
		
		if(hitPos > 0)
		{
			ballVY += hitPos/REDUCEPOWER;
		} else
		{

			ballVY -= hitPos/REDUCEPOWER;
		}

		ballVX = -ballVX;
	}
}
