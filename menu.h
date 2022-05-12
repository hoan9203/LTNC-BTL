#ifndef MENU_H_ 
#define MENU_H_
#include "base.h"

void menuload(LTexture & gMENUTexture,SDL_Renderer * gRenderer);
void menuevent(SDL_Event & e,LTexture &gMENUTexture,bool &checkmenu);


#endif