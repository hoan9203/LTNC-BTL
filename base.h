#ifndef BASE_H_
#define BASE_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;



class LTexture
{
	public:

		LTexture();
	
		~LTexture();
		
		

		bool loadFromFile( string path ,SDL_Renderer * gRenderer);
		
		bool loadFromText(string text, string textFont, SDL_Color textColor, int size, SDL_Renderer * gRenderer);
		
		void free();

		void setColor( Uint8 red, Uint8 green, Uint8 blue );


		void setBlendMode( SDL_BlendMode blending );


		void setAlpha( Uint8 alpha );
		

		void render( int x, int y,SDL_Renderer *gRenderer = NULL ,SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );


		int getWidth();
		int getHeight();

	private:

		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;

		TTF_Font * font;

};
#endif