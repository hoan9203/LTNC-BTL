#include "menu.h"

void menuload(LTexture &gMENUTexture,SDL_Renderer * gRenderer) 
{
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( gRenderer );
	    gMENUTexture.loadFromFile("menu.png",gRenderer);
		gMENUTexture.render(0 , 0 , gRenderer);
		SDL_RenderPresent( gRenderer );
		SDL_Delay(3000);
}
	