#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
	Entity(Vector2f p_pos,int p_w, int p_h, SDL_Texture* p_tex);
	Vector2f& getPos();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();	
	void setPos(float p_x, float p_y);
private:
	Vector2f vecPos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};