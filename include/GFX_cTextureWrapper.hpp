/**
 * Wrapper class for Texture classes, common interface .. etc
 */
#ifndef CTEXTUREWRAPPER_H
#define CTEXTUREWRAPPER_H

#include <SDL2/SDL_opengl.h>

typedef unsigned int GLuint;

namespace GFX
{
    class cTextureWrapper
    {
    public:
        void        BindGL() const;
        const int GetWidth() const;
        const int GetHeight() const;
        const GLuint GetID() const;
        const float GetU() const;
        const float GetV() const;
        const float GetU2() const;
        const float GetV2() const;
        const void GetTextureCoordinates(float& u, float& v, float& u2, float& v2) const;
        void SetTextureCoordinates(float u, float v, float u2, float v2);
    protected:
        int m_width, m_height;
        float m_u, m_v, m_u2, m_v2;
        GLuint m_texture_id;

    }; // End class cTextureWrapper

    inline void cTextureWrapper::BindGL() const
    { glBindTexture(GL_TEXTURE_2D, m_texture_id); }

    inline const int cTextureWrapper::GetWidth() const
    { return m_width; }

    inline const int cTextureWrapper::GetHeight() const
    { return m_height; }

    inline const GLuint cTextureWrapper::GetID() const
    { return m_texture_id; }

    inline const void cTextureWrapper::GetTextureCoordinates(float& u, float& v, float& u2, float& v2) const
    {
        u = m_u;
        v = m_v;
        u2 = m_u2;
        v2 = m_v2;
    }

    inline void cTextureWrapper::SetTextureCoordinates(float u, float v, float u2, float v2)
    {
        m_u = u;
        m_v = v;
        m_u2 = u2;
        m_v2 = v2;
    }

    inline const float cTextureWrapper::GetU() const
    { return m_u; }

    inline const float cTextureWrapper::GetV() const
    { return m_v; }

    inline const float cTextureWrapper::GetU2() const
    { return m_u2; }

    inline const float cTextureWrapper::GetV2() const
    { return m_v2; }

} // End namespace GFX
#endif // CTEXTUREWRAPPER_H
