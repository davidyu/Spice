#ifndef CANIMATIONREGISTRY_H
#define CANIMATIONREGISTRY_H

#include "global_inc.hpp"
#include "GFX_G2D_cAnimation.hpp"

namespace CORE
{
    class cGame;
}


namespace GFX
{
    class cAnimationRegistry
    {
    public:
        cAnimationRegistry();
        virtual ~cAnimationRegistry();

        void RegisterAnimation(GFX::G2D::cAnimation& anim);
        GFX::G2D::cAnimation& GetAnimation(int i);

        void UpdateCurrent(float delta);
        void Render(CORE::cGame& game, float delta);

        void Reset();
    private:
        std::vector<GFX::G2D::cAnimation> m_Anims;
        int m_CurrentIndex;

    };
}
#endif // CANIMATIONREGISTRY_H
