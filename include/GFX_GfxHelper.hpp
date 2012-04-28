#ifndef GFXHELPER_H
#define GFXHELPER_H

#include <SDL2/SDL_opengl.h>
#include "GFX_cTextureWrapper.hpp"

namespace GFX
{
    inline unsigned int GetColourInHex(unsigned int col)
    { return (col & 0xffffff00) >> 8; }

    inline void ImmediateRenderTexturePos2Dim2(cTextureWrapper& tex, float x, float y, float w, float h)
    {
        glBindTexture(GL_TEXTURE_2D, tex.GetID());               // Select Our Texture

        const float u   = tex.GetU();
        const float v   = tex.GetV();
        const float u2  = tex.GetU2();
        const float v2  = tex.GetV2();

        const float x2 = x+w;
        const float y2 = y+h;

        glBegin(GL_QUADS);
            glTexCoord2f(u, v);     glVertex3f(x,  y,  1.0f);
            glTexCoord2f(u2, v);    glVertex3f(x2,  y,  1.0f);
            glTexCoord2f(u2, v2);   glVertex3f(x2, y2,  1.0f);
            glTexCoord2f(u, v2);    glVertex3f(x, y2,  1.0f);
        glEnd();
    }

    inline void ImmediateRenderTexturePos2Dim2Origin2Scale2Rot(cTextureWrapper& tex, float x, float y, float w, float h
                                               , float x_origin, float y_origin
                                               , float x_scale, float y_scale, float rot_degrees)
    {
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

        glBindTexture(GL_TEXTURE_2D, tex.GetID());               // Select Our Texture

        glBegin(GL_QUADS);
            glTexCoord2f(u, v);     glVertex3f(x1,  y1,  1.0f);
            glTexCoord2f(u2, v);    glVertex3f(x2,  y2,  1.0f);
            glTexCoord2f(u2, v2);   glVertex3f(x3, y3,  1.0f);
            glTexCoord2f(u, v2);    glVertex3f(x4, y4,  1.0f);
        glEnd();
    }


} // End namespace GFX

#endif // GFXHELPER_H
