/**
 *
 */
#include "GFX_G2D_cSpriteBatch.hpp"
#include "GFX_cTextureWrapper.hpp"
#include "GFX_cTextureMesh.hpp"

using namespace GFX;
using namespace G2D;

cSpriteBatch::cSpriteBatch()
{
}

cSpriteBatch::~cSpriteBatch()
{
}


void cSpriteBatch::DrawTexture(cTextureWrapper& tex, float x, float y, float w, float h)
{
    // if (!m_is_drawing) throw Exception... // TODO

    if (tex.GetID() != m_last_texture->GetID()) {
        RenderMesh();
        m_last_texture = &tex;
    }
    else if (m_index >= mn_verticies) {
        RenderMesh();
    }

    const float rx2 = x + w;
    const float ry2 = y + h;
    const float u   = tex.GetU();
    const float v   = tex.GetV();
    const float u2  = tex.GetU2();
    const float v2  = tex.GetV2();

    m_mesh->AddVertex4f(x, y, u, v);
    m_mesh->AddVertex4f(x, ry2, u, v2);
    m_mesh->AddVertex4f(rx2, ry2, u2, v2);
    m_mesh->AddVertex4f(rx2, y, u2, v);
}

void cSpriteBatch::RenderMesh()
{
    if (m_index == 0) {
        return;
    }
    m_last_texture->BindGL();
}
