#ifndef CORTHOCAM_H
#define CORTHOCAM_H

#include "GFX_cCameraBase.hpp"
#include "MATH_LinearAlgebra.hpp"

using namespace MATH;

namespace GFX
{
    class cOrthoCamera : public cCameraBase
    {
    public:
        cOrthoCamera();
        cOrthoCamera(cRectf& vp);
        ~cOrthoCamera();
        void Translatef(float x, float y);

        const Vec2f& GetPos() const;
        cRectf& GetViewportRect() { return m_Viewport; }
        void    SetViewportRect(cRectf& vp) { m_Viewport = vp; }

    private:
        cRectf m_Viewport;
    };

    inline const Vec2f& cOrthoCamera::GetPos() const
    {
        return Vec2f(cCameraBase::GetPos().x, cCameraBase::GetPos().y);
    }
}

#endif // CORTHOCAM_H
