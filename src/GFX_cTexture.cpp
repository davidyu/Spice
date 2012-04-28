/**
 *
 */

#include "GFX_cTexture.hpp"
#include "GFX_cImage.hpp"
#include <GL/glu.h>

#include <iostream>

using namespace GFX;

cTexture::~cTexture()
{}

//
cTexture::cTexture(const string& str_filepath)
: mp_image(new cImage(str_filepath))
{
	m_is_transparent = mp_image->IsTransparent();
	m_texture_id = 0;
    SetTextureWidth(mp_image->GetWidth());
	SetTextureHeight(mp_image->GetHeight());
	SetUV(0.0f, 0.0f, 1.0f, 1.0f);
}

//
const bool cTexture::operator==(const cTexture& rhs) const
{
	return (mp_image.get() == rhs.mp_image.get()) && (GetID() == rhs.GetID());
}

//
void cTexture::RegisterGL()
{
	glGenTextures (1, &m_texture_id);
	std::cout << m_texture_id << std::endl;

//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glEnable(GL_BLEND);

	glBindTexture (GL_TEXTURE_2D, m_texture_id);

	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_NEAREST and GL_NEAREST -> no filter -> Crisp
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	mp_image->ConvertPixelFormat();

	int width = GetTextureWidth();
	int height = GetTextureHeight();

	if (((width & (width-1)) == 0) && ((height & (height-1)) == 0))
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, mp_image->GetPixels());
	else
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGBA, GL_UNSIGNED_BYTE, mp_image->GetPixels());

    CheckTexture();

//	mp_image.reset();


}
