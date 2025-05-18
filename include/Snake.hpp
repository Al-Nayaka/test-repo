#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class Snake : public Entity
{
public :
	Snake(Vector2f p_pos,int p_w, int p_h, SDL_Texture* p_tex);
	bool checkCollision(SDL_Rect b);
	void input(SDL_Event& e);
	void update(SDL_Rect p_a, bool& ateApple);
private :
	Vector2f vecVelocity;
	Vector2f vecDir;
};