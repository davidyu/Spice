/**
 *
 */

#include "GFX_cTexture.hpp"
#include "GFX_cImage.hpp"
#include <GL/glu.h>

using namespace GFX;

cTexture::~cTexture()
{}

//
cTexture::cTexture(const string& str_filepath)
: mp_image(new cImage(str_filepath))
{
	m_is_transparent = mp_image->IsTransparent();
	m_texture_id = INVALID_ID;

    SetTextureWidth(mp_image->GetWidth());
	SetTextureHeight(mp_image->GetHeight());
	m_u         = 0.0f;
	m_v         = 0.0f;
	m_u2        = 1.0f;
	m_v2        = 1.0f;
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
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_NEAREST and GL_NEAREST -> no filter -> Crisp
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	mp_image->ConvertPixelFormat();

	int width = GetTextureWidth();
	int height = GetTextureHeight();

	if (((width & (width-1)) == 0) && ((height & (height-1)) == 0))
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, mp_image->GetPixels());
	else
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA8, width, height, GL_RGBA, GL_UNSIGNED_BYTE, mp_image->GetPixels());

	mp_image.reset();

	CheckTexture();
}
