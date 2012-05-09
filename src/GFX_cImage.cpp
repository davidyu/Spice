#include "GFX_cImage.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

using namespace GFX;
using std::cout;
using std::endl;

cImage::cImage(const string& str_filepath)
: m_pSurface(0)
, m_nColors(0)
, m_TextureFormat(0)
{
	//	load the image file
	m_pSurface = IMG_Load(str_filepath.c_str());
	if (m_pSurface==0) {
	    //throw cImageLoadException(SDL_GetError());
	    cout << "Could not load: " << str_filepath << endl;
	}
	CheckImage();

	m_nColors = m_pSurface->format->BytesPerPixel;
}

bool cImage::IsTransparent() const
{
    Uint32 key = 0;
	return (m_pSurface->format->Amask != 0) || (SDL_GetColorKey(m_pSurface, &key) != -1);
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

    if (m_nColors == 4) {
        if (m_pSurface->format->Rmask == 0x000000ff)
            m_TextureFormat = GL_RGBA;
        else
            m_TextureFormat = GL_BGRA;
    } else if (m_nColors == 3) {
        if (m_pSurface->format->Rmask == 0x000000ff)
            m_TextureFormat = GL_RGB;
        else
            m_TextureFormat = GL_BGR;
    } else {
            printf("warning: the image is not truecolor..  this will probably break\n");
            // this error should not go unhandled
    }
//    SDL_Color color;
//    SDL_GetRGB(*(Uint32 *)m_pSurface->pixels, m_pSurface->format, &color.r, &color.g, &color.b);
//	SDL_Surface* p_alpham_pSurface = SDL_CreateRGBSurface(0, GetWidth(), GetHeight(),
//													  32, rmask, gmask, bmask, amask);
//	SDL_BlitSurface(m_pSurface, 0, p_alpham_pSurface, 0);
//	SDL_FreeSurface(m_pSurface);
//	m_pSurface = p_alpham_pSurface;


}
