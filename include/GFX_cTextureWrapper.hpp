/**
 * Wrapper class for Texture classes, common interface .. etc
 */
#ifndef CTEXTUREWRAPPER_H
#define CTEXTUREWRAPPER_H

#include <SDL2/SDL_opengl.h>

#define INVALID_ID GL_INVALID_VALUE

namespace GFX
{
    class cTextureWrapper
    {
    public:
        cTextureWrapper(){}
        void        BindGL() const;
        const int GetTextureWidth() const;
        const int GetTextureHeight() const;
        const GLuint GetID() const;
        const float GetU() const;
        const float GetV() const;
        const float GetU2() const;
        const float GetV2() const;
        const void GetUV(float& u, float& v, float& u2, float& v2) const;
        const float GetDeltaU() const;
        const float GetDeltaV() const;
        void SetUV(float u, float v, float u2, float v2);
        void SetTextureWidth(float w);
        void SetTextureHeight(float h);

    protected:
        int m_texture_width, m_texture_height;
        float m_u, m_v, m_u2, m_v2;
        GLuint m_texture_id;

    }; // End class cTextureWrapper

    inline void cTextureWrapper::BindGL() const
    { glBindTexture(GL_TEXTURE_2D, m_texture_id); }

    inline const int cTextureWrapper::GetTextureWidth() const
    { return m_texture_width; }

    inline const int cTextureWrapper::GetTextureHeight() const
    { return m_texture_height; }

    inline const GLuint cTextureWrapper::GetID() const
    { return m_texture_id; }

    inline const void cTextureWrapper::GetUV(float& u, float& v, float& u2, float& v2) const
    {
        u = m_u;
        v = m_v;
        u2 = m_u2;
        v2 = m_v2;
    }

    inline const float cTextureWrapper::GetU() const
    { return m_u; }

    inline const float cTextureWrapper::GetV() const
    { return m_v; }

    inline const float cTextureWrapper::GetU2() const
    { return m_u2; }

    inline const float cTextureWrapper::GetV2() const
    { return m_v2; }

    inline const float cTextureWrapper::GetDeltaU() const
    { return m_u2 - m_u;}

    inline const float cTextureWrapper::GetDeltaV() const
    { return m_v2 - m_v;}

    inline void cTextureWrapper::SetUV(float u, float v, float u2, float v2)
    {
        m_u = u;
        m_v = v;
        m_u2 = u2;
        m_v2 = v2;
    }

    inline void cTextureWrapper::SetTextureWidth(float w)
    { m_texture_width = w; }
    inline void cTextureWrapper::SetTextureHeight(float h)
    { m_texture_height = h; }
} // End namespace GFX
#endif // CTEXTUREWRAPPER_H
