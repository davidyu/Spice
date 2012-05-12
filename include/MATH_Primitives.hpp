#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "MATH_Vec2.hpp"

namespace MATH
{
    class cRectf
    {
    public:
        cRectf() : m_Topleft(), m_Dim() {}
        cRectf(float left, float top, float width, float height)
        : m_Topleft(Vec2f(left, top)), m_Dim(Vec2f(width, height)) {}

        inline const float Left() const { return m_Topleft.x; }
        inline const float Right() const { return m_Topleft.x+m_Dim.x; }
        inline const float Bottom() const { return m_Topleft.y+m_Dim.y; }
        inline const float Top() const { return m_Topleft.y; }

        inline bool IsCollidedRect(const cRectf& rect)
        {
            return (!((Right()<rect.Left())
                  ||(Left()>rect.Right())
                  ||(Top()>rect.Bottom())
                  ||(Bottom()<rect.Top())));
        }

    private:
        Vec2f m_Topleft, m_Dim;
    };

}

#endif // PRIMITIVES_H
