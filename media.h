#ifndef MEDIA_H_
#define MeDIA_H_

#include "base.h"

extern SDL_Window* gWindow ;

extern SDL_Renderer* gRenderer;

extern bool init();

extern bool loadMedia(LTexture &gPLANETexture,LTexture &gBGTexture);

extern void close(SDL_Window *gWindow,SDL_Renderer *gRenderer,LTexture &gBGTexture,LTexture &gPLANETexture);







#endif