#ifndef FIRE_H_
#define FIRE_H_
#include "base.h"

class fire
{
    public:
		static const int FIRE_WIDTH = 40;
		static const int FIRE_HEIGHT = 37;

		fire();

		void render(SDL_Renderer * gRenderer,LTexture &gFIRETexture);
		
		int fireX, fireY;
		
};

#endif