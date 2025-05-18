#include "Entity.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(Vector2f p_pos,int p_w, int p_h, SDL_Texture* p_tex)
:vecPos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_w;
	currentFrame.h = p_h;
}

Vector2f& Entity::getPos() 
{ 
	return vecPos; 
}

SDL_Texture* Entity::getTex()
{ 
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{ 
	return currentFrame; 
}

void Entity::setPos(float p_x, float p_y)
{
	vecPos.x = p_x;
	vecPos.y = p_y;
}