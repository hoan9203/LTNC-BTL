#include "base.h"
#include "player.h"
#include "media.h"
#include "bullet.h"
#include "aura.h"
#include "menu.h"
#include "enemy.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

LTexture gMENUTexture;
LTexture gPLAYERTexture;
LTexture gBGTexture;
LTexture gENEMYTexture;
LTexture gBULLETTExture;
LTexture gAURATexture;
LTexture gEXTexture;

int main( int argc, char* args[] )
{
	bool check_fire = false, check_enemy = false , check_bloom = false;
	int mVelS = 0, clip = 0 , clip2 = 0, clip3 = -1 ;
	int delay = 60, delay2 = 90;
	SDL_Event e;
	
	srand(time(0));
	
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else

	{
			bool quit = false,speedup = false ;
			
			player player;
			bullet bullet;
			aura aura;
			enemy enemy[7];
			explosion explosion;
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
									case SDLK_LEFT :
										{
										if (!check_fire)
										{
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
										switch( e.key.keysym.sym ) 
										{
										case SDLK_RIGHT:
										{
											mVelS = 0; 
											speedup = false;
											gAURATexture.free();
											for (int i = 0; i < 7 ; i++)
												enemy[i].eVelX += 10;
										}; break;
										}
									}
						}
					
				player.move();
				bullet.move(gBULLETTExture);
				
				if (speedup)
					{
						setclipgifaura(gAURATexture, clip);
						aura.auraX = player.mPosX -70;
						aura.auraY = player.mPosY -20;
					}
				
				if (check_fire) {
					for(int i = 0 ; i < 7 ; i++)
							 	if (!check_bloom)
								 	enemy[i].checkcollisionbullet(bullet.bPosX,bullet.bPosY,explosion,check_bloom);
					setclipgifkame(gBULLETTExture,clip2);
					clip2 ++;
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
								
								enemy[i].ePosY = 100*i;
								enemy[i].ePosX =  SCREEN_WIDTH + 150*(rand()%(6 - 0 + 1) + 0) ;
								
								check_enemy = true;

							}
						if (check_bloom) {
							clip3++;
							setclipgifbloom(gEXTexture,clip3);
							if (clip3 == 28) {
								check_bloom = false;
								clip3 = -1;
							}
						}

						for (int i = 0; i < 7; i++) {
							enemy[i].move(gENEMYTexture);
							enemy[i].checkcollisionplayer(player.mPosX,player.mPosY);
						}
						if (delay2 < 0) {
							check_enemy = false;
							delay2 = 120;
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
				aura.render(gRenderer,gAURATexture);
				explosion.render(gRenderer,gEXTexture);
				SDL_RenderPresent( gRenderer );
			}
	}
	close(gWindow,gRenderer,gBGTexture,gPLAYERTexture);

	return 0;
}