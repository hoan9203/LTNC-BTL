
#ifndef PLAYER_H_
#define PLAYER_H_
#include "base.h"

class player
{
    public:
		static const int PLAYER_WIDTH = 60;
		static const int PLAYER_HEIGHT = 30;
		static const int PLAYER_VEL = 8;
		
		int mPosX, mPosY;
		
		player();

		void handleEvent( SDL_Event& e );

		void move();

		void render(SDL_Renderer * gRenderer,LTexture &gPLAYERTexture);

    private:

		int mVelX, mVelY;
		
};

#endif