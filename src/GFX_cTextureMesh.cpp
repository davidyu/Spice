/**
 * cTextureMesh based somewhat on globjview on dhpoware
 */
 #include <SDL2/SDL_opengl.h>
#include "GFX_cTextureMesh.hpp"


using namespace GFX;

cTextureMesh::cTextureMesh()
{
    mn_verticies = 0;
    m_use_vbo = true;

    m_vertex_buffer.reserve(90);
    m_index_buffer.reserve(30);
}

cTextureMesh::~cTextureMesh()
{
    Destroy();
}

void cTextureMesh::Destroy()
{
    m_vertex_buffer.clear();
    m_index_buffer.clear();
}

void cTextureMesh::Render()
{
    // Enable client states and add array data
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, GetVertexByteSize(), GetVertexBuffer()->pos);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, GetVertexByteSize(),GetVertexBuffer()->tex_coord);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4, GL_FLOAT, GetVertexByteSize(),GetVertexBuffer()->col);

    // Draw
    glDrawElements(GL_TRIANGLES, GetNumberOfIndicies(), GL_UNSIGNED_INT, GetIndexBuffer());

    // Disable client states
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
