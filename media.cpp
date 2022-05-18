#include "media.h"


bool init()
{
    
	bool success = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		gWindow = SDL_CreateWindow( "Plane Control", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{

			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
			
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia(LTexture &gPLANETexture,LTexture &gBGTexture)
{
	bool success = true;


	if( !gBGTexture.loadFromFile( "bg25601.jpg",gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	
	return success;

}

void close(SDL_Window *gWindow,SDL_Renderer *gRenderer,LTexture &gBGTexture,LTexture &gPLANETexture)
{

	gPLANETexture.free();
	gBGTexture.free();
	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
void setclipgif(LTexture &gPLANETexture, int &clip) {
	switch (clip)
	{
	case 0:  gPLANETexture.loadFromFile( "gokugif/gokugif-0.png",gRenderer); break;
	case 4 : gPLANETexture.loadFromFile( "gokugif/gokugif-1.png",gRenderer); break;
	case 8 : gPLANETexture.loadFromFile( "gokugif/gokugif-2.png",gRenderer); break;
	case 12 : gPLANETexture.loadFromFile( "gokugif/gokugif-3.png",gRenderer); break;
	}
}
void setclipgif2(LTexture &gPLANETexture, int &clip2) {
	switch (clip2)
	{
	case 120:  gPLANETexture.loadFromFile( "gokugif2/goku-gif-18-0.png",gRenderer); break;
	case 110 : gPLANETexture.loadFromFile( "gokugif2/goku-gif-18-1.png",gRenderer); break;
	case 100 : gPLANETexture.loadFromFile( "gokugif2/goku-gif-18-2.png",gRenderer); break;
	case 90 : gPLANETexture.loadFromFile( "gokugif2/goku-gif-18-3.png",gRenderer); break;
	case 80 : gPLANETexture.loadFromFile( "gokugif2/goku-gif-18-4.png",gRenderer); break;
	case 70 : gPLANETexture.loadFromFile( "gokugif2/goku-gif-18-5.png",gRenderer); break;
	
	
	}
}
void setclipgifaura(LTexture &gFIRETexture, int &clip) {
	switch (clip)
	{
	case 0:  gFIRETexture.loadFromFile( "aura/aura1.png",gRenderer); break;
	case 4 : gFIRETexture.loadFromFile( "aura/aura2.png",gRenderer); break;
	case 8 : gFIRETexture.loadFromFile( "aura/aura3.png",gRenderer); break;
	case 12 : gFIRETexture.loadFromFile( "aura/aura4.png",gRenderer); break;
	
	}
}

void setclipgifkame(LTexture &gBULLETTexture, int &clip) {
	switch (clip)
	{
		
		case 0 : gBULLETTexture.loadFromFile( "kiblast/ki-blast-1.png",gRenderer); break;
		case 4 : gBULLETTexture.loadFromFile( "kiblast/ki-blast-2.png",gRenderer); break;
		case 8 : gBULLETTexture.loadFromFile( "kiblast/ki-blast-3.png",gRenderer); break;
		case 12: gBULLETTexture.loadFromFile( "kiblast/ki-blast-4.png",gRenderer); break;
		case 16: gBULLETTexture.loadFromFile( "kiblast/ki-blast-5.png",gRenderer); break;
		
	}

}