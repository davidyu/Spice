#include "GFX_cOrthoCamera.hpp"

using namespace GFX;

cOrthoCamera::cOrthoCamera()
             :m_Viewport()
{}

cOrthoCamera::cOrthoCamera(cRectf& vp)
             :m_Viewport(vp)
{}

cOrthoCamera::~cOrthoCamera() {}

void cOrthoCamera::Translatef(float x, float y)
{
    cCameraBase::Translatef(x, y, 0);
    m_Viewport.SetTop(m_Pos.y);
    m_Viewport.SetLeft(m_Pos.x);
}
