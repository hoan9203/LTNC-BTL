#include "explosion.h"
explosion::explosion(){};


void explosion::render(SDL_Renderer * gRenderer,LTexture &gEXPLOSIONTexture)
{
    gEXPLOSIONTexture.render( ePosX, ePosY,gRenderer );
}

