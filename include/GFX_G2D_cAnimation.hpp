// CAnimation class based on the same from libgdx

#ifndef CANIMATION_H
#define CANIMATION_H

#include <vector>
#include "MATH_MathHelper.hpp"
#include "GFX_cTextureWrapper.hpp"

namespace GFX
{
    class cTextureWrapper;
    namespace G2D
    {
        class cAnimation
        {
        public:
            cAnimation();
            cAnimation(float ticks_per_frame, std::vector<cTextureWrapper> frames);

            virtual ~cAnimation();

            void ClearAll();
            void PushFrame(const cTextureWrapper& frame);

            const cTextureWrapper& GetKeyFrame(float statetime, bool is_looping) const;

            // Setters
            void SetTicksPerFrame(float tpf);

        private:
            std::vector<cTextureWrapper> m_frames;
            float m_ticks_per_frame;
            float m_total_ticks;
        };  // End class cAnimation

        inline const cTextureWrapper& cAnimation::GetKeyFrame(float statetime, bool is_looping) const
        {
            int frame_index = static_cast<int>(statetime/m_ticks_per_frame);

            if (is_looping) {
                frame_index %= m_frames.size();
            } else {
                frame_index = MATH::minf(frame_index, m_frames.size()-1);
            }
            return m_frames[frame_index];
        }
    }   // End namespace G2D
}   // End namespace GFX


#endif // CANIMATION_H
