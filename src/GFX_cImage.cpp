#include "GFX_cImage.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

using namespace GFX;
using std::cout;
using std::endl;

cImage::cImage(const string& str_filepath)
{
	//	load the image file
	mp_surface = IMG_Load(str_filepath.c_str());
	if (mp_surface==0) {
	    //throw cImageLoadException(SDL_GetError());
	    cout << "Could not load: " << str_filepath << endl;
	}
	CheckImage();
}

bool cImage::IsTransparent() const
{
    Uint32 key = 0;
	return (mp_surface->format->Amask != 0) || (SDL_GetColorKey(mp_surface, &key) != -1);
}

void cImage::ConvertPixelFormat()
{
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;
#else
    Uint32 rmask = 0x000000ff;
    Uint32 gmask = 0x0000ff00;
    Uint32 bmask = 0x00ff0000;
    Uint32 amask = 0xff000000;
#endif
	//SDL_SetSurfaceAlphaMod(mp_surface, SDL_ALPHA_TRANSPARENT);
	SDL_Surface* p_alphasurface = SDL_CreateRGBSurface(SDL_SWSURFACE, GetWidth(), GetHeight(),
													  32, rmask, gmask, bmask, amask);
	SDL_BlitSurface(mp_surface, 0, p_alphasurface, 0);
	SDL_FreeSurface(mp_surface);
	mp_surface = p_alphasurface;
}
