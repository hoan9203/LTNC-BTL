#include "base.h"
#include "plane.h"
#include "media.h"
#include "bullet.h"
#include "fire.h"
#include "menu.h"
#include "enemy.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

LTexture gMENUTexture;
LTexture gPLANETexture;
LTexture gBGTexture;
LTexture gENEMYTexture;
LTexture gBULLETTExture;
LTexture gFIRETexture;

int main( int argc, char* args[] )
{
	bool check_fire = false;
	int mVelS = 0, count ;
	int delay = 120, delay2 = 120;
	SDL_Event e;
	
	srand(time(0));
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
			bool quit = false,speedup = false, check_enemy = false;
			
			plane plane;
			bullet bullet;
			fire fire;
			enemy enemy[5];
			int scrollingOffset = 0;
			//menuload(gMENUTexture,gRenderer);
			loadMedia( gPLANETexture,gBGTexture);
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
							mVelS =15;
							speedup = true;
							for (int i = 0; i < 5 ; i++)
								enemy[i].eVelX -= 10;
						} break;
						case SDLK_LEFT :{
							 if (check_fire == false){ 
							 bullet.bPosX = plane.mPosX;
							 bullet.bPosY = plane.mPosY;
							 gBULLETTExture.loadFromFile( "kame.png" ,gRenderer) ;
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
							 mVelS = 0; 
							 speedup = false;
							 gFIRETexture.free();
							 for (int i = 0; i < 5 ; i++)
								enemy[i].eVelX += 10;
						} break;
						}
    				}
				}
					
				plane.move();
				if (speedup)
				{
							gFIRETexture.loadFromFile("gokuaura.png",gRenderer);
							fire.fireX = plane.mPosX-10;
							fire.fireY = plane.mPosY-10;
				}
				
				bullet.move(gBULLETTExture);
				if (check_fire)
					if (delay < 0) {
					check_fire = false;
					delay = 120;	
					
				}

					
						
						gENEMYTexture.loadFromFile("enemy.png",gRenderer);
						if (!check_enemy)		
							for (int i = 0; i < 5 ; i++) {
							
								enemy[i].ePosY = 40*(rand()%(10 - 0 + 1) + 0);
								enemy[i].ePosX =  SCREEN_WIDTH + 50*(rand()%(10 - 0 + 1) + 0) ;
							
								check_enemy = true;
							}
						for (int i = 0; i< 5; i ++)
							enemy[i].move(gENEMYTexture);
						
						if (delay2 < 0) {
							check_enemy = false;
							delay2 = 120;
							count ++;
						}
				
				delay --;	
				delay2 --;
				scrollingOffset -=3;	
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
				
				for (int i = 0 ; i < 5 ; i ++) 
					enemy[i].render(gRenderer, gENEMYTexture);
				plane.render(gRenderer,gPLANETexture);
				bullet.render(gRenderer,gBULLETTExture);
				fire.render(gRenderer,gFIRETexture);
				
				SDL_RenderPresent( gRenderer );
			}
	}
	close(gWindow,gRenderer,gBGTexture,gPLANETexture);

	return 0;
}