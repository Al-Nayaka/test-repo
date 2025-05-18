#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class Apple : public Entity
{
public:
	Apple(Vector2f p_pos,int p_w, int p_h, SDL_Texture* p_tex);
	SDL_Rect getColApple();
	void randomizer(int& p_x, int& p_y);
	void updateApple();
private:
	SDL_Rect colApple;
};