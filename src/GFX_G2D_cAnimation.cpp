/**
 *
 */
#include "GFX_G2D_cAnimation.hpp"
#include "GFX_cTextureWrapper.hpp"

using namespace GFX::G2D;

cAnimation::cAnimation()
{

}
cAnimation::cAnimation(float ticks_per_frame, std::vector<cTextureWrapper>& frames)
{
    m_frames = frames;
    SetTicksPerFrame(ticks_per_frame);
}

cAnimation::~cAnimation()
{
    ClearAll();
}

void cAnimation::ClearAll()
{
    m_frames.clear();
}
void cAnimation::PushFrame(const GFX::cTextureWrapper& frame)
{
    m_frames.push_back(frame);
    m_total_ticks += m_ticks_per_frame;
}

void cAnimation::SetTicksPerFrame(float tpf)
{
    m_ticks_per_frame = tpf;
    m_total_ticks = m_ticks_per_frame * m_frames.size();
}
