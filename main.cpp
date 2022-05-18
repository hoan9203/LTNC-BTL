#include "base.h"
#include "player.h"
#include "media.h"
#include "bullet.h"
#include "fire.h"
#include "menu.h"
#include "enemy.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

LTexture gMENUTexture;
LTexture gPLAYERTexture;
LTexture gBGTexture;
LTexture gENEMYTexture;
LTexture gBULLETTExture;
LTexture gFIRETexture;

int main( int argc, char* args[] )
{
	bool check_fire = false, check_enemy = false;
	int mVelS = 0, count , clip = 0 , clip2 = 0 ;
	int delay = 60, delay2 = 100;
	SDL_Event e;
	
	srand(time(0));
	
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
			bool quit = false,speedup = false;
			
			player player;
			bullet bullet;
			fire fire;
			enemy enemy[7];
			int scrollingOffset = 0;
			menuload(gMENUTexture,gBGTexture,gRenderer);
			loadMedia( gPLAYERTexture,gBGTexture);
				while( !quit )
					{
					if (clip == 12)
						clip = 0;
					
					setclipgif(gPLAYERTexture,clip);
						
					
					while( SDL_PollEvent( &e ) != 0 )
						{
					
							if( e.type == SDL_QUIT )
								{
									quit = true;
								}
						player.handleEvent( e );
					
					if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    					{
        					switch( e.key.keysym.sym )
        						{
						case SDLK_RIGHT: 
						{
							
							mVelS =15;
							speedup = true;
							for (int i = 0; i < 7 ; i++)
								enemy[i].eVelX -= 10;
						} break;
						case SDLK_LEFT :{
							 if (!check_fire){ 
								
								bullet.bPosX = player.mPosX;
								bullet.bPosY = player.mPosY +15;
								bullet.changeVel();
							 	check_fire = true;							 
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
							 for (int i = 0; i < 7 ; i++)
								enemy[i].eVelX += 10;
						} break;
						}
    				}
					}
					
				player.move();
				
				if (speedup)
					{
						setclipgifaura(gFIRETexture, clip);
						fire.fireX = player.mPosX -70;
						fire.fireY = player.mPosY -20;
					}
				
				bullet.move(gBULLETTExture);
				if (check_fire) {
					
					setclipgifkame(gBULLETTExture,clip2);
					clip2++;
					delay --;
					
					if (delay < 0) {
						check_fire = false;
						delay = 60;						
					}	
					if (clip2 == 16)
						clip2 = 0;	
					}			
				

					
						
						gENEMYTexture.loadFromFile("enemy.png",gRenderer);
						if (!check_enemy)		
							for (int i = 0; i < 7 ; i++) {
							
								enemy[i].ePosY = 90*(rand()%(7 - 0 + 1) + 0);
								enemy[i].ePosX =  SCREEN_WIDTH + 150*(rand()%(6 - 0 + 1) + 0) ;
							
								check_enemy = true;
							}
						for (int i = 0; i< 7; i ++)
							enemy[i].move(gENEMYTexture);
						
						if (delay2 < 0) {
							check_enemy = false;
							delay2 = 100;
							count ++;
						}
								
				delay2 --;
				clip ++;
				
				scrollingOffset-= 3 + mVelS;

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
				
				for (int i = 0 ; i < 7 ; i ++) 
					enemy[i].render(gRenderer, gENEMYTexture);
				player.render(gRenderer,gPLAYERTexture);
				bullet.render(gRenderer,gBULLETTExture);
				fire.render(gRenderer,gFIRETexture);
				
				SDL_RenderPresent( gRenderer );
			}
	}
	close(gWindow,gRenderer,gBGTexture,gPLAYERTexture);

	return 0;
}