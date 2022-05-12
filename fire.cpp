#include "fire.h"


fire::fire()
{
    
}

void fire::render(SDL_Renderer * gRenderer,LTexture &gFIRETexture)
{
	gFIRETexture.render( fireX, fireY,gRenderer );
}