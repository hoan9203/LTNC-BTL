
#ifndef PLANE_H_
#define PLANE_H_
#include "base.h"

class plane
{
    public:
		static const int PLANE_WIDTH = 60;
		static const int PLANE_HEIGHT = 30;
		static const int PLANE_VEL = 8;
		
		int mPosX, mPosY;
		
		plane();

		void handleEvent( SDL_Event& e );

		void move();

		void render(SDL_Renderer * gRenderer,LTexture &gPLANETexture);

    private:

		
		
		int mVelX, mVelY;
		
};

#endif