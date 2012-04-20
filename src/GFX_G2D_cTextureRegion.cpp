/**
 *
 */
#include "GFX_G2D_cTextureRegion.hpp"

using namespace GFX;
using namespace G2D;

std::vector<cTextureWrapper> cTextureRegion::SplitTextureHorizontal(const cTextureWrapper& tex, int frame_width, int y_offset)
{

}

cTextureRegion::cTextureRegion()
{
    //ctor
}

cTextureRegion::~cTextureRegion()
{
    //dtor
}

cTextureRegion::cTextureRegion(const cTextureWrapper& tex, int x_offset, int y_offset, int width, int height)
{
    CopyTextureWrapper(tex);
    SetRegionFromDimensions(tex, x_offset, y_offset, width, height);
}

cTextureRegion::cTextureRegion(const cTextureWrapper& tex, float u, float v, float u2, float v2)
{
    CopyTextureWrapper(tex);
    SetRegionFromUV(tex, u, v, u2, v2);
}

cTextureRegion::cTextureRegion(const cTextureWrapper& tex)
{
    CopyTextureWrapper(tex);
    SetUV(0.0f, 0.0f, 1.0f, 1.0f);
}

void cTextureRegion::CopyTextureWrapper(const cTextureWrapper& rhs)
{
    SetUV(rhs.GetU(), rhs.GetV(), rhs.GetU2(), rhs.GetV2());
    SetTextureWidth(rhs.GetTextureWidth());
    SetTextureHeight(rhs.GetTextureHeight());
    m_texture_id = rhs.GetID();
}

void cTextureRegion::SetRegionFromDimensions(const cTextureWrapper& tex, int x_offset, int y_offset, int width, int height)
{
    const float u_offset = tex.GetU();
    const float v_offset = tex.GetV();
    const float texture_width = static_cast<float>(tex.GetTextureWidth());
    const float texture_height = static_cast<float>(tex.GetTextureHeight());
    const float inverse_texture_width = 1.0f / texture_width;
    const float inverse_texture_height = 1.0f / texture_height;

    const float x = static_cast<float>(x_offset);
    const float y = static_cast<float>(y_offset);
    const float w = static_cast<float>(width);
    const float h = static_cast<float>(height);

    SetUV( (x        + u_offset * texture_width)*inverse_texture_width
        ,  (y       + v_offset * texture_height)*inverse_texture_height
        ,  ((x+w)    + u_offset * texture_width)*inverse_texture_width
        ,  ((y+h)   + v_offset * texture_height)*inverse_texture_height);
}

void cTextureRegion::SetRegionFromWholeTexture(const cTextureWrapper& tex)
{
    m_texture_id = tex.GetID();
    SetUV(tex.GetU(), tex.GetV(), tex.GetU2(), tex.GetV2());
}

void cTextureRegion::SetRegionFromUV(const cTextureWrapper& tex, float u, float v, float u2, float v2)
{
    const float u_offset = tex.GetU();
    const float v_offset = tex.GetV();
    const float delta_u = tex.GetDeltaU();
    const float delta_v = tex.GetDeltaV();

    SetUV( (u*delta_u+u_offset)
        ,  (v*delta_v+v_offset)
        ,  (u2*delta_u+u_offset)
        ,  (v2*delta_v+v_offset));
}


