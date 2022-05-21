#include "aura.h"


aura::aura() {};

void aura::render(SDL_Renderer * gRenderer,LTexture &gAURATexture)
{
	gAURATexture.render( auraX, auraY,gRenderer );
}