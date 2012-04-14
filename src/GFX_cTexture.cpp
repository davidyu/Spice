/**
 *
 */

#include "GFX_cTexture.hpp"
#include "GFX_cImage.hpp"
#include <GL/glu.h>

using namespace GFX;

const GLuint cTexture::INVALID_ID = ~1;


cTexture::~cTexture()
{
    //dtor
}

//
cTexture::cTexture(const string& str_filepath)
: m_texture_id(INVALID_ID)
, mp_image(new cImage(str_filepath))
{
	m_is_transparent = mp_image->IsTransparent();
}

//
const bool cTexture::operator==(const cTexture& rhs) const
{
	return (mp_image == rhs.mp_image) && (GetID() == rhs.GetID());
}

//
void cTexture::RegisterGL()
{
	CheckTexture();

	glGenTextures (1, &m_texture_id);
	glBindTexture (GL_TEXTURE_2D, m_texture_id);

	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // GL_NEAREST is not blurry. Crisp
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	mp_image->ConvertPixelFormat();

	const int w = mp_image->GetWidth();
	const int h = mp_image->GetHeight();

	if (((w & (w-1)) == 0) && ((h & (h-1)) == 0))
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, mp_image->GetPixels());
	else
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA8, w, h, GL_RGBA, GL_UNSIGNED_BYTE, mp_image->GetPixels());

	mp_image.reset();

	CheckTexture();
}
