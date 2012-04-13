#ifndef CCAMERABASE_H
#define CCAMERABASE_H

#include "MATH_LinearAlgebra.hpp"

using namespace MATH;

namespace GFX
{
    class cCameraBase
    {
    public:
        cCameraBase();
        virtual ~cCameraBase();

        // Apply the projection and view matricies
        void ApplyMatricies();
        void Translatef(float x, float y, float z);
        void Unproject(const Vec3f& vec);
        void UnprojectCustom(const Vec3f& vec, float viewport_x, float viewport_y, float viewport_w, float viewport_h);

        const Vec3f& GetPos() const     { return m_pos; }
        float GetAspectRatio() const    { return m_aspect_ratio; }
        float GetNear() const           { return m_near; }
        float GetFar()  const           { return m_far; }
        float GetViewportWidth() const  { return m_viewport_w; }
        float GetViewportHeight() const { return m_viewport_h; }

    protected:
        Vec3f m_pos;
        Vec3f m_dir;

        Matrix4x4 m_projection;
        Matrix4x4 m_view;
        Matrix4x4 m_combined;

        float m_near, m_far;
        float m_viewport_w, m_viewport_h;
        float m_aspect_ratio;

    private:

    }; // End class cCameraBase

} // End namespace GFX

#endif // CCAMERABASE_H
