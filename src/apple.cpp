#include "Apple.hpp"
#include "Entity.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <cstdlib>
#include <ctime>

Apple::Apple(Vector2f p_pos,int p_w, int p_h, SDL_Texture* p_tex):Entity(p_pos, p_w, p_h, p_tex)
{
	colApple.x = getPos().x;
	colApple.y = getPos().y;
	colApple.w = getPos().x + getCurrentFrame().w;
	colApple.h = getPos().y + getCurrentFrame().h;
}

SDL_Rect Apple::getColApple()
{
	return colApple;
}

void Apple::randomizer(int& p_x, int& p_y)
{
	srand((unsigned) time(NULL));

	p_x = rand() % 257;
	p_x = p_x - (p_x % 32);

	p_y = rand() % 257;
	p_y = p_y - (p_y % 32);
}

void Apple::updateApple()
{
	int p_x = 0; 
	int p_y = 0;
	randomizer(p_x, p_y);
	setPos(p_x, p_y);
}
