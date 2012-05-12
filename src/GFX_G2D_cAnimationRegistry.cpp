#include "cAnimationRegistry.hpp"

#include "CORE_cGame.hpp"

using namespace GFX;

cAnimationRegistry::cAnimationRegistry()
: m_Anims()
, m_CurrentIndex(0)
{

}

cAnimationRegistry::~cAnimationRegistry()
{

}

void cAnimationRegistry::RegisterAnimation(GFX::G2D::cAnimation& anim)
{
    m_Anims.push_back(anim);

}

GFX::G2D::cAnimation& cAnimationRegistry::GetAnimation(int i)
{
    return m_Anims[i];
}

void cAnimationRegistry::Reset()
{
    m_Anims.clear();
}
