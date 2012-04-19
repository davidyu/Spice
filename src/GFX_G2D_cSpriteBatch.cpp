/**
 *
 */
#include "GFX_G2D_cSpriteBatch.hpp"
#include "GFX_cTextureWrapper.hpp"
#include "GFX_cTextureMesh.hpp"
#include "memory_macros.h"

using namespace GFX;
using namespace GFX::G2D;

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


void cSpriteBatch::DrawTexture(cTextureWrapper& tex, float x, float y, float w, float h)
{
    // if (!m_is_drawing) throw Exception... // TODO

    if (m_last_texture!=0 && tex.GetID() != m_last_texture->GetID()) {
        RenderMesh();
        ChangeTexture(tex);
    }
    else if (m_index >= mn_max_batch) {
        RenderMesh();
    }
    m_last_texture = &tex;

    const float x2 = x + w;
    const float y2 = y + h;
    const float u   = tex.GetU();
    const float v   = tex.GetV();
    const float u2  = tex.GetU2();
    const float v2  = tex.GetV2();

    m_mesh->AddVertex4f(x2, y2, u2, v2);
    m_mesh->AddVertex4f(x, y2, u, v2);
    m_mesh->AddVertex4f(x, y, u, v);
    m_mesh->AddVertex4f(x2, y, u2, v);

    m_index += 4;
}

void cSpriteBatch::RenderMesh()
{
    if (m_index == 0 || m_last_texture ==0) {
        return;
    }
    m_last_texture->BindGL();
    m_mesh->Render();

    m_index = 0;
}

void cSpriteBatch::ChangeTexture(cTextureWrapper& tex)
{
    m_last_texture = &tex;
    m_reciprocal_tex_width = 1.0f/tex.GetTextureWidth();
    m_reciprocal_tex_height = 1.0f/tex.GetTextureHeight();

}
