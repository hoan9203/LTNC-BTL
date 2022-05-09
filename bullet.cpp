#include "bullet.h"
bullet::bullet()
{
    bPosX = 100;
    bPosY = 0 ;
    bVelX = 0;
}
void bullet::changeVel()
{
    bVelX +=20;
};

void bullet::move(LTexture &gBULLETTexture)
{
    bPosX +=bVelX;
    if (bPosX > SCREEN_WIDTH) {
        gBULLETTexture.free();
        bVelX = 0;
    }
}


void bullet::render(SDL_Renderer * gRenderer,LTexture &gBULLETTexture)
{
	gBULLETTexture.render( bPosX, bPosY,gRenderer );
}