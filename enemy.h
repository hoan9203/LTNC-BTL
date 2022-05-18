#ifndef ENEMY_H_
#define ENEMY_H_

#include "base.h"

class enemy
{
    public:
		static const int ENEMY_WIDTH = 60;
		static const int ENEMY_HEIGHT = 33;

		enemy();

		void move(LTexture &gENEMYTexture);


		void render(SDL_Renderer * gRenderer,LTexture &gENEMYTexture);
		
		void checkcollisionbullet(int posx ,int posy);
		
		void checkcollisionplayer(int posx, int posy);
		
		int ePosX, ePosY;
		int eVelX;
		
};


#endif
