#include "Snake.hpp"
#include "Apple.hpp"
#include "Entity.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//screen size
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;

Snake::Snake(Vector2f p_pos,int p_w, int p_h, SDL_Texture* p_tex):Entity(p_pos, p_w, p_h, p_tex) 
{
	vecVelocity.x = 32;
	vecVelocity.y = 32;
	vecDir.x = 1;
	vecDir.y = 0;
}

bool Snake::checkCollision(SDL_Rect b)
{
	if(getPos().x >= b.w)
		return false;
	if (getPos().x + getCurrentFrame().w <= b.x)
		return false;
	if (getPos().y >= b.h)
		return false;
	if (getPos().y + getCurrentFrame().h <= b.y)
		return false;
	return true;
}

void Snake::input(SDL_Event& e)
{
	if (e.type != SDL_KEYDOWN && e.key.repeat != 0)
	{
		std::cout << "Pressed other mouse button or something broke..." << std::endl;
	}

	//take input
	if(vecDir.x == 0)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_a : vecDir.x = -1; vecDir.y = 0; break;
			case SDLK_d : vecDir.x = 1; vecDir.y = 0; break;		
		}
		//std::cout << "dir x : " << vecDir.x << std::endl;
	}
	if(vecDir.y == 0)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_w : vecDir.x = 0; vecDir.y = -1; break;
			case SDLK_s : vecDir.x = 0; vecDir.y = 1; break;
		}
		//std::cout << "dir y : " << vecDir.y << std::endl;
	}
}

void Snake::update(SDL_Rect p_a, bool& ateApple)
{
	//change direction of snake
	setPos(getPos().x + vecVelocity.x * vecDir.x, getPos().y + vecVelocity.y * vecDir.y);

	//Not out of border
	if((getPos().x < 0) || (getPos().x + getCurrentFrame().w > SCREEN_WIDTH/2) || (getPos().y < 0) || (getPos().y + getCurrentFrame().h > SCREEN_HEIGHT/2))
			// setPos(getPos().x - vecVelocity.y * vecDir.x, getPos().y - vecVelocity.y * vecDir.y);
		std::cout << "hit wall" << std::endl;
	if(checkCollision(p_a))
	{	
		ateApple = true;
		std::cout << "ate apple" << std::endl;
	}

	// std::cout << "pos x : " << getPos().x + getCurrentFrame().w << std::endl;
	// std::cout << "pos y : " << getPos().y + getCurrentFrame().h << std::endl;
}