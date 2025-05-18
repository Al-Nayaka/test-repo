#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Snake.hpp"
#include "Apple.hpp"

//Create window
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
RenderWindow window("Snake", SCREEN_WIDTH  , SCREEN_HEIGHT );

//game variable
const float TIMESTEP = 5;
float accumulator = 0.0f;
float currentTime = SDL_GetTicks64();

bool gameRunning = true;
bool ateApple = false;
int score = 0;
SDL_Event event;

//Game Texture
SDL_Texture* white = window.loadTexture("res/gfx/White.png");
SDL_Texture* red = window.loadTexture("res/gfx/Red.png");

//Game Object
//Snake
Snake snake(Vector2f((SCREEN_WIDTH/4) - 64 ,SCREEN_HEIGHT/4), 32, 32, white);

//Apple
Apple apple(Vector2f(snake.getPos().x + 64, snake.getPos().y), 32, 32, red);
SDL_Rect appleCol;

void init()
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
}

void destroyWin()
{
	window.cleanUp();
	SDL_Quit();
}

void update()
{
	float newTime = SDL_GetTicks64();
	float deltaTime = newTime - currentTime;

	if(deltaTime > 0.25f)
		deltaTime = 0.25f;

	currentTime = newTime;
	accumulator += deltaTime;

	while(accumulator >= TIMESTEP)
	{
		//Apple rect
		appleCol.x = apple.getPos().x;
		appleCol.y = apple.getPos().y;
		appleCol.w = apple.getPos().x + apple.getCurrentFrame().w;
		appleCol.h = apple.getPos().y + apple.getCurrentFrame().h;

		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT :
					gameRunning = false;
					break;
				case SDL_KEYDOWN :
					if (event.key.keysym.sym == SDLK_ESCAPE)
						gameRunning = false;
					break;
			}
			snake.input(event);
		}
		snake.update(appleCol, ateApple);
		if (ateApple)
		{
			apple.updateApple();
			ateApple = false;
			score++;

			//std::cout << score << std::endl;
		}		
		std::cout << apple.getPos().x << std::endl;

		accumulator -= TIMESTEP;		
	}	
}

void draw()
{
	window.clear();
	window.render(snake);
	window.render(apple);
	window.display();
}

int main(int argc, char* args[])
{	
	init();
	//MAIN LOOP
	while (gameRunning)
	{
		int startTicks = SDL_GetTicks64();

		update();
		draw();

		int frameTicks = SDL_GetTicks64() - startTicks;
		if (frameTicks < 1000 / window.getRefreshRate())
		{
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
		}
	}

	destroyWin();

	return 0;
}