#ifndef GFX_MOTIONBLUR_H
#define GFX_MOTIONBLUR_H

#include "global_inc.hpp"
#include "GFX_TextureUtilities.hpp"

namespace GFX
{

    struct MotionBlurTexture
    {
        int width, height, channels, format;
    };

    bool CreateMotionBlurTexture(int quality, int interpolation, cTextureWrapper& tex);

//    void RenderToMotionBlurTexture(bool FirstRenderTexture, iGameState* state, CORE::cGame);
}



#endif // GFX_MOTIONBLUR_H
