
#ifndef BULLET_H_
#define BULLET_H_
#include "base.h"


class bullet
{
    public:
		static const int Bullet_WIDTH = 10;
		static const int Bullet_HEIGHT = 10;

		bullet();

		void move(LTexture &gBULLETTexture);
		
		void changeVel();

		void render(SDL_Renderer * gRenderer,LTexture &gBULLETTexture);
		
		int bPosX, bPosY;
    private:

		int bVelX;
		
};

#endif