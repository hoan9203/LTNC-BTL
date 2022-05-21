#include "base.h"
#include "player.h"
#include "media.h"
#include "bullet.h"
#include "aura.h"
#include "menu.h"
#include "enemy.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL; 

LTexture gTexture;
LTexture gMENUTexture;
LTexture gPLAYERTexture;
LTexture gBGTexture;
LTexture gENEMYTexture;
LTexture gBULLETTExture;
LTexture gAURATexture;
LTexture gEXTexture;
LTexture gPointTexture;
LTexture gScoreTexture;
LTexture gGameover1;                                                                                                                                                                                                                                                                                                                                                                                                                                      
LTexture gGameover2; 
LTexture gHighscore;
LTexture gHighscoreText;

int flag = 0;
Uint8 a = 255;


int main( int argc, char* args[] )
{
	
	bool check_fire = false, check_enemy = false , check_bloom = false, check_enter = false,check_space = false ,check_loss = false;
	int mVelS = 0, clip = 0 , clip2 = 0, clip3 = -1 ;
	int delay = 120, delay2 = 90;
	long long score = 0, highscore = 0;
	
	SDL_Event e;
	Mix_Chunk * chunk = NULL , *chunk2 = NULL, *chunk3 = NULL;
	Mix_Music* music = NULL;
	srand(time(0));
	
	gMENUTexture.setBlendMode(SDL_BLENDMODE_BLEND);

	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else

	{
			bool quit = false,speedup = false ;
			gENEMYTexture.loadFromFile("enemy.png",gRenderer);
			
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
					printf("%s", Mix_GetError());
			music = Mix_LoadMUS("backgroundsound.mp3");
				if (music == NULL)
					printf("%s", Mix_GetError());
			
			chunk = Mix_LoadWAV("AIR.wav");
			chunk2 = Mix_LoadWAV("kame.wav");
			chunk3 = Mix_LoadWAV("explosion.wav");
			Mix_PlayMusic(music, -1);
			player player;
 			bullet bullet;
			aura aura;
			enemy enemy[7];
			explosion explosion;
			int scrollingOffset = 0;
			menuload(gMENUTexture,gBGTexture,gTexture,gRenderer);
				while( !quit )
					{
					if (clip == 12)
						clip = 0;
					
					setclipgif(gPLAYERTexture,clip);
					SDL_Color color1 = {255,253,85};
					string scoreS = to_string(score/10);
					string highscoreS = to_string(highscore/10);
					gScoreTexture.loadFromText(scoreS,"font1.otf",color1,30,gRenderer);
					gPointTexture.loadFromText("SCORE","font1.otf",color1,30,gRenderer);
					gHighscore.loadFromText(highscoreS,"font1.otf",color1,30,gRenderer);
					gHighscoreText.loadFromText("HIGH SCORE","font1.otf",color1,30,gRenderer);
					while( SDL_PollEvent( &e ) != 0 )
						 {
							if( e.type == SDL_QUIT )
								{
									quit = true;
								}
							player.handleEvent( e );
							if (flag == 0) {
								if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) check_enter = true;
							}
							if (check_loss) 
								if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) 
									{
										check_loss = false;
										score = 0;
										delay2 = 90;
										check_enemy = false;
									}
							if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    							{
        							switch( e.key.keysym.sym )
        							{
									case SDLK_RIGHT: 
									{ 		
										if (!check_loss)
											mVelS =15;
										speedup = true;
										for (int i = 0; i < 7 ; i++)
										enemy[i].eVelX -= 10;
									} break;
									case SDLK_LEFT :
										{
										if (!check_fire)
											if (!check_loss)
										{
											bullet.bPosX = player.mPosX;
											bullet.bPosY = player.mPosY +15;
											bullet.changeVel();
							 				check_fire = true;							 
							 				Mix_PlayChannel(-1, chunk2, 0);
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
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				if (check_enter) {
					if (flag == 0) {
						loadMedia( gPLAYERTexture,gBGTexture);
						while (a > 0) {
							a-=5;
							gBGTexture.render(0,0,gRenderer);
							gMENUTexture.setAlpha(a);
							gMENUTexture.render(0,0, gRenderer);
							SDL_RenderPresent(gRenderer);
						}
						flag++;
						gMENUTexture.free();
					}
				player.move();
				
				bullet.move(gBULLETTExture);
				
				if (speedup)
					if (!check_loss)
					{
						setclipgifaura(gAURATexture, clip);
						aura.auraX = player.mPosX -70;
						aura.auraY = player.mPosY -20;
						Mix_PlayChannel(-1, chunk, 0);
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
						delay = 120;						
					}	
					
					if (clip2 == 16)
						clip2 = 0;	
					}			
					
						
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
							Mix_PlayChannel(-1, chunk3, 0);
						}

						if(!check_loss)
						for (int i = 0; i < 7; i++) {
							enemy[i].move(gENEMYTexture);
							enemy[i].checkcollisionplayer(player.mPosX,player.mPosY, check_loss);
							
						}
						if (delay2 < 0) {
							check_enemy = false;
							delay2 = 90;
						}
				

				delay2 --;
				clip ++;
				
				if (!check_loss) scrollingOffset-= 3 + mVelS;
				score += 3 +mVelS;
				if( scrollingOffset > 0 )
				{
					scrollingOffset = -gBGTexture.getWidth();
				}
				if( scrollingOffset < -gBGTexture.getWidth() )
				{
					scrollingOffset = 0;
				}

				
				
				gBGTexture.render( scrollingOffset, 0 ,gRenderer);
				gBGTexture.render( scrollingOffset + gBGTexture.getWidth(), 0,gRenderer );			
				gScoreTexture.render(900,30,gRenderer);
				gPointTexture.render(900,0,gRenderer);
				gHighscore.render(1100,30,gRenderer);
				gHighscoreText.render(1100,0,gRenderer);
				
				for (int i = 0 ; i < 7 ; i ++) 
					enemy[i].render(gRenderer, gENEMYTexture);			
				if (!check_loss) {
				player.render(gRenderer,gPLAYERTexture);
				bullet.render(gRenderer,gBULLETTExture);
				aura.render(gRenderer,gAURATexture);
				explosion.render(gRenderer,gEXTexture);
				}
				if (check_loss)
					{
						gGameover1.loadFromText("You Are Dead","font1.otf",color1,100,gRenderer);
						gGameover2.loadFromText("Press SPACE to play again","font1.otf",color1,100,gRenderer);
						gGameover1.render(300,250, gRenderer);
						gGameover2.render(100,350, gRenderer);
		
						score -= 3 +mVelS;
						highscore = max(highscore,score);
					}
						gGameover1.free();
						gGameover2.free();
						gHighscore.free();
						gHighscoreText.free();
						SDL_RenderPresent( gRenderer );
				
			}
			else {
				menuload(gMENUTexture, gBGTexture, gTexture, gRenderer);
			}
		}
	}
	close(gWindow,gRenderer,gBGTexture,gPLAYERTexture);

	return 0;
}