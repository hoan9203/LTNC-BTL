#include "enemy.h"
enemy::enemy()
{
    //eVelX = -10 - 2*(rand()% (4 - 0 + 1 ) +0 );
    eVelX = -20;
}


void enemy::move(LTexture &gENEMYTexture)
{
    ePosX +=eVelX;
    
}


void enemy::render(SDL_Renderer * gRenderer,LTexture &gENEMYTexture)
{
    gENEMYTexture.render( ePosX, ePosY,gRenderer );
}