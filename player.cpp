#include "player.h"

player::player()
{
    mPosX = 100;
    mPosY = 0 ;
    mVelX = 0;
    mVelY = 0;
}

void player::handleEvent( SDL_Event& e )
{
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: 
                mVelY -= PLAYER_VEL; break;
            case SDLK_DOWN: mVelY += PLAYER_VEL; break;
            
        }
    } 
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += PLAYER_VEL; break;
            case SDLK_DOWN: mVelY -= PLAYER_VEL; break;
           
        }
    }
}

void player::move()
{
    //mPosX += mVelX;
    if( ( mPosX < 0 ) || ( mPosX + PLAYER_WIDTH > SCREEN_WIDTH ) )
    {
        mPosX -= mVelX;
    }

    mPosY += mVelY;
    if( ( mPosY < 0 ) || ( mPosY + PLAYER_HEIGHT > SCREEN_HEIGHT -80 ) )
    {
        mPosY -= mVelY;
    }
}


void player::render(SDL_Renderer * gRenderer,LTexture &gPLAYERTexture)
{
	gPLAYERTexture.render( mPosX, mPosY,gRenderer );
}