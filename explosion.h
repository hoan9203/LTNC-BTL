#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "base.h"

class explosion
{
    public:
		static const int EXPLOSION_WIDTH = 60;
		static const int EXPLOSION_HEIGHT = 33;

		explosion();

		void render(SDL_Renderer * gRenderer,LTexture &gEXPLOSIONTexture);		

		int ePosX, ePosY;
		
};


#endif
