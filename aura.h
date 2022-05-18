#ifndef AURA_H_
#define AURA_H_
#include "base.h"

class aura
{
    public:
		static const int AURA_WIDTH = 40;
		static const int AURA_HEIGHT = 37;

		aura();

		void render(SDL_Renderer * gRenderer,LTexture &gAURATexture);
		
		int auraX, auraY;
		
};

#endif