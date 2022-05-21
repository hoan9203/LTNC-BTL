#include "menu.h"

void menuload(LTexture &gMENUTexture,LTexture &gBGTexture,LTexture &gTexture,SDL_Renderer * gRenderer) 
{
			SDL_Color color = {0,0,0};

			gTexture.loadFromText("Press ENTER to start game","font1.otf",color,40,gRenderer);	
	    	gMENUTexture.loadFromFile("menu.jpg",gRenderer);	
			gMENUTexture.render(0 , 0 , gRenderer);
			gTexture.render(50,550,gRenderer);
			
			SDL_RenderPresent( gRenderer );	
}
	