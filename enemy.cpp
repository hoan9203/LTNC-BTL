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

void enemy::checkcollisionbullet(int posx, int posy) 
{
    if ( (ePosY -30 < posy) && (ePosY +60 > posy) && (ePosX < posx) )
        ePosX = -100;
}
void enemy::checkcollisionplayer(int posx, int posy) 
{
    if ( (ePosY-50 < posy) && (ePosY +60 > posy) && (ePosX < posx) &&(ePosX +70 > posx)){
        ePosX = -100;
        SDL_Delay(500);
    }
}