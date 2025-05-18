#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow 
{
	public:
		RenderWindow(const char* p_title, int p_w, int p_h);
		int getRefreshRate();
		SDL_Texture* loadTexture(const char* P_FILEPATH);
		void render(Entity& p_entity);
		void display();
		void clear();
		void cleanUp();

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		int32_t centreX, centreY, radius;
};