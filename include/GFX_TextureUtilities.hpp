#ifndef GFXHELPER_H
#define GFXHELPER_H

#include "global_inc.hpp"


namespace GFX
{
    class cTextureWrapper;

    inline unsigned int GetColourInHex(unsigned int col)
    { return (col & 0xffffff00) >> 8; }

    void ImmediateRenderTexturePos2Dim2(cTextureWrapper& tex, float x, float y, float w, float h);

    void ImmediateRenderTexturePos2Dim2Origin2Scale2Rot(cTextureWrapper& tex, float x, float y, float w, float h
                                               , float x_origin, float y_origin
                                               , float x_scale, float y_scale, float rot_degrees);

    // Generate texture routine taken from Full Scene Motion Blur By Stanciu Vlad
    bool GenerateTexture(GLuint &Texture, int SizeX, int SizeY, int Channels, int Format, int Min_Filter, int Mag_Filter);

    bool GenerateTexture(GLuint &Texture, int SizeX, int SizeY, int Channels, int Format, int Min_Filter, int Mag_Filter, unsigned int *memoryArea);


} // End namespace GFX

#endif // GFXHELPER_H
