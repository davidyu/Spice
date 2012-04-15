#ifndef CTEXTUREMESH_H
#define CTEXTUREMESH_H

#include <vector>

namespace GFX
{

class cTextureMesh
{
public:
    struct Vertex
    {
        float pos[2];       //!< x and y coord
        float tex_coord[2]; //!< u and v coord
        float colour[4];    //!< rgba
    };

                        cTextureMesh();
    virtual             ~cTextureMesh();

    void                Destroy();
    void                AddVertex8f(float x, float y, float u, float v
                                  , float r, float g, float b, float a);
    void                AddVertex(const Vertex& vertex);

    // Getters
    const int*          GetIndexBuffer() const;
    int                 GetIndexSize() const;
    int                 GetNumberOfIndicies() const;
    int                 GetNumberOfVerticies() const;

    const Vertex&       GetVertex(int i) const;
    const Vertex&       GetVertexBuffer() const;
    const int           GetVertexByteSize() const;

private:
    int                 mn_verticies;
    bool                m_use_vbo;

    std::vector<Vertex> m_vertex_buffer;
    std::vector<int>    m_index_buffer;

};

}

inline void cTextureMesh::AddVertex8f(float x, float y, float u, float v
                                    , float r, float g, float b, float a)
{
    Vertex vertex = {
        x, y,
        u, v,
        r, g, b, a
    };
    AddVertex(vertex);
}

inline void cTextureMesh::AddVertex(const Vertex& vertex)
{
    int index = static_cast<int> m_index_buffer.size();

    m_index_buffer.push_back(index);
    m_vertex_buffer.push_back(vertex);
}
#endif // CTEXTUREMESH_H
