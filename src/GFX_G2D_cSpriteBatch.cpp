/**
 *
 */
#include "GFX_G2D_cSpriteBatch.hpp"
#include "GFX_cTextureWrapper.hpp"
#include "GFX_cTextureMesh.hpp"
#include "MATH_MathHelper.hpp"
#include "memory_macros.h"

using namespace GFX;
using namespace GFX::G2D;

#define c m_current_color

cSpriteBatch::cSpriteBatch()
// Delegated ctor
{
    Initialise(100);
}

cSpriteBatch::cSpriteBatch(int n_batch)

{
    Initialise(n_batch);
}

void cSpriteBatch::Initialise(int n_batch)
{
    mn_max_batch = n_batch;
    m_index = 0;
    m_is_blending_enabled = false;
    m_mesh = new cTextureMesh(n_batch);
    m_current_color.set(1.0f, 1.0f, 1.0f, 1.0f);
}

cSpriteBatch::~cSpriteBatch()
{
    DELETESINGLE(m_mesh);
}

void cSpriteBatch::Begin()
{
    if (m_is_drawing){
        // Throw exception
    }
    m_index = 0;
    m_is_drawing = true;
    m_mesh->Destroy();
    m_last_texture = 0;

}

void cSpriteBatch::End()
{
    if (!m_is_drawing) {
        // Throw exception
    }
    if (m_index > 0) {
        RenderMesh();
    }
    m_is_drawing = false;
}


void cSpriteBatch::DrawTexture(const cTextureWrapper& tex, float x, float y, float w, float h)
{
    // if (!m_is_drawing) throw Exception... // TODO

    FlushIfNewTextureOrBatchFull(tex);
    ChangeTexture(tex);

    const float x2 = x + w;
    const float y2 = y + h;
    const float u   = tex.GetU();
    const float v   = tex.GetV();
    const float u2  = tex.GetU2();
    const float v2  = tex.GetV2();

    m_mesh->AddVertex8f(x, y, u, v, c.r, c.g, c.b, c.a);
    m_mesh->AddVertex8f(x2, y, u2, v, c.r, c.g, c.b, c.a);
    m_mesh->AddVertex8f(x2, y2, u2, v2, c.r, c.g, c.b, c.a);
    m_mesh->AddVertex8f(x, y2, u, v2, c.r, c.g, c.b, c.a);

    m_index += 4;
}

void cSpriteBatch::DrawTexturePos2Dim2Origin2Scale2Rot(const cTextureWrapper& tex, float x, float y, float w, float h
                                   , float x_origin, float y_origin
                                   , float x_scale, float y_scale, float rot_degrees)
{
    FlushIfNewTextureOrBatchFull(tex);
    ChangeTexture(tex);

    const float x_world = x + x_origin;
    const float y_world = y + y_origin;
    const float fx = -x_origin * x_scale;
    const float fy = -y_origin * y_scale;
    const float fx2 = (w - x_origin) * x_scale;
    const float fy2 = (h - y_origin) * y_scale;

    const float p1x = fx;
    const float p1y = fy;
    const float p2x = fx2;
    const float p2y = fy;
    const float p3x = fx2;
    const float p3y = fy2;
    const float p4x = fx;
    const float p4y = fy2;

    float x1 = p1x;
    float y1 = p1y;
    float x2 = p2x;
    float y2 = p2y;
    float x3 = p3x;
    float y3 = p3y;
    float x4 = p4x;
    float y4 = p4y;

    if (!MATH::CloseTof(rot_degrees, 0.0f)) {
        const float cos_v = MATH::cos_deg(rot_degrees);
        const float sin_v = MATH::sin_deg(rot_degrees);

        x1 = cos_v * p1x - sin_v * p1y;
        y1 = sin_v * p1x + cos_v * p1y;

        x2 = cos_v * p2x - sin_v * p2y;
        y2 = sin_v * p2x + cos_v * p2y;

        x3 = cos_v * p3x - sin_v * p3y;
        y3 = sin_v * p3x + cos_v * p3y;

        x4 = x1 + (x3 - x2); // < Interesting!
        y4 = y3 - (y2 - y1);
    }
    x1 += x_world;
    y1 += y_world;
    x2 += x_world;
    y2 += y_world;
    x3 += x_world;
    y3 += y_world;
    x4 += x_world;
    y4 += y_world;

    const float u   = tex.GetU();
    const float v   = tex.GetV();
    const float u2  = tex.GetU2();
    const float v2  = tex.GetV2();

    m_mesh->AddVertex8f(x1, y1, u, v, c.r, c.g, c.b, c.a);
    m_mesh->AddVertex8f(x2, y2, u2, v, c.r, c.g, c.b, c.a);
    m_mesh->AddVertex8f(x3, y3, u2, v2, c.r, c.g, c.b, c.a);
    m_mesh->AddVertex8f(x4, y4, u, v2, c.r, c.g, c.b, c.a);

    m_index += 4;

}

void cSpriteBatch::RenderMesh()
{
    if (m_index == 0 || m_last_texture ==0) {
        return;
    }
    m_last_texture->BindGL();
    m_mesh->Render();
}

void cSpriteBatch::ChangeTexture(const cTextureWrapper& tex)
{
    m_last_texture = &tex;
    m_reciprocal_tex_width = 1.0f/tex.GetTextureWidth();
    m_reciprocal_tex_height = 1.0f/tex.GetTextureHeight();

}

 void cSpriteBatch::FlushIfNewTextureOrBatchFull(const cTextureWrapper& tex)
 {
    if (m_last_texture!=0 && tex.GetID() != m_last_texture->GetID()) {
        RenderMesh();
        m_mesh->Destroy();
        ChangeTexture(tex);
    } else if (m_index >= mn_max_batch) {
        RenderMesh();
    }
 }


 void cSpriteBatch::SetColor(const Color4 col)
 {
    m_current_color = col;
 }
