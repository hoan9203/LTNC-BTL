#include "menu.h"

void menuload(LTexture &gMENUTexture,LTexture &gBGTexture,SDL_Renderer * gRenderer) 
{
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( gRenderer );
	    gMENUTexture.loadFromFile("menu.png",gRenderer);
		gBGTexture.loadFromFile("bg25601.jpg",gRenderer);
		gBGTexture.render( 0 , 0 , gRenderer);		
		gMENUTexture.render(0 , 0 , gRenderer);
		SDL_RenderPresent( gRenderer );
		SDL_Delay(5000);
}
	