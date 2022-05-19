#ifndef MEDIA_H_
#define MeDIA_H_

#include "base.h"


extern SDL_Window* gWindow ;

extern SDL_Renderer* gRenderer;

extern bool init();

extern bool loadMedia(LTexture &gPLANETexture,LTexture &gBGTexture);

extern void close(SDL_Window *gWindow,SDL_Renderer *gRenderer,LTexture &gBGTexture,LTexture &gPLANETexture);

extern void setclipgif(LTexture &gPLANETexture, int &clip);

extern void setclipgif2(LTexture &gPLANETexture, int &clip2);

extern void setclipgifaura(LTexture &gFIRETexture, int &clip);

extern void setclipgifkame(LTexture &gBULLLETTexture, int &clip);

extern void setclipgifbloom(LTexture &gEXTexture, int &clip);

#endif