#include "base.h"
#include "plane.h"
#include "media.h"
#include "bullet.h"
#include "fire.h"

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

LTexture gPLANETexture;
LTexture gBGTexture;
LTexture gBULLETTExture;
LTexture gFIRETexture;

int main( int argc, char* args[] )
{
	bool check_fire = false;
	int mVelS = 0;
	int delay = 120;
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !loadMedia( gPLANETexture,gBGTexture) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			bool quit = false;

			SDL_Event e;

			plane plane;

			bullet bullet;
			
			fire fire;

			int scrollingOffset = 0;
			
			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{

					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					

					plane.handleEvent( e );
				if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    				{
        				switch( e.key.keysym.sym )
        				{
						case SDLK_RIGHT: 
						{
							mVelS +=10;
							gFIRETexture.loadFromFile("fire2.bmp",gRenderer);
							fire.fireX = plane.mPosX-20;
							fire.fireY = plane.mPosY;
						
						} break;
						case SDLK_LEFT :{
							 if (check_fire == false){
							 
							 bullet.bPosX = plane.mPosX+10;
							 bullet.bPosY = plane.mPosY+20;
							 gBULLETTExture.loadFromFile( "rocket.bmp" ,gRenderer) ;
							 check_fire = true;
							 bullet.changeVel();
							 	}
							}; break;
						}

    				}
				else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    				{
        				switch( e.key.keysym.sym ) {
            			case SDLK_RIGHT:{
							 mVelS -= 10; 
							 gFIRETexture.free();	
						} break;
						}
    				}
				}

				plane.move();
				
				bullet.move(gBULLETTExture);
				if (check_fire)
					if (delay < 0) {
					check_fire = false;
					delay = 120;
					
				}
				delay --;	
				scrollingOffset --;	
				scrollingOffset-=mVelS;

				if( scrollingOffset > 0 )
				{
					scrollingOffset = -gBGTexture.getWidth();
				}
				if( scrollingOffset < -gBGTexture.getWidth() )
				{
					scrollingOffset = 0;
				}


				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				
				gBGTexture.render( scrollingOffset, 0 ,gRenderer);
				gBGTexture.render( scrollingOffset + gBGTexture.getWidth(), 0,gRenderer );
				
				
				plane.render(gRenderer,gPLANETexture);
				bullet.render(gRenderer,gBULLETTExture);
				fire.render(gRenderer,gFIRETexture);
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	close(gWindow,gRenderer,gBGTexture,gPLANETexture);

	return 0;
}