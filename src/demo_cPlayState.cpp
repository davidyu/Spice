#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>
#include "demo_cPlayState.hpp"
#include "STATE_cGameTransition.hpp"
#include "CORE_cGame.hpp"
#include "GFX_cImage.hpp"
#include "GFX_cTexture.hpp"
#include "GFX_G2D_cTextureRegion.hpp"
#include "GFX_G2D_cSpriteBatch.hpp"
#include "GFX_G2D_cAnimation.hpp"
#include "GFX_cTextureRegistry.hpp"
#include "GFX_GfxHelper.hpp"

    #include <iostream>
    using namespace std;

using namespace GFX;
using namespace GFX::G2D;

namespace
{
    cTexture* p_tex;
}

cPlayState::cPlayState() {}
cPlayState::~cPlayState() {}

STATE::iGameState* cPlayState::CreateInstance()
{
    return new cPlayState;
}
STATE::iGameState* cPlayState::Clone()
{
    return new cPlayState;
}


//cTexture* p_tex2;
bool cPlayState::OnEnter()
{
    cout << "Entering State\n";
    p_tex = new cTexture("art/split.png");
    p_tex->RegisterGL();
    test = false;


    return true;
}
bool cPlayState::OnExit()
{
    cout << "Leaving state\n";
}
void cPlayState::Pause() {}
void cPlayState::Resume() {}




void cPlayState::Update(CORE::cGame* game, float delta)
{
    HandleInput(game);
}

void cPlayState::Render(CORE::cGame* game, float percent_tick)
{
    static G2D::cSpriteBatch batch = G2D::cSpriteBatch();

    static cTextureRegion reg = cTextureRegion(*p_tex, 16, 16, 48, 16);
    static cTextureRegion reg2 = cTextureRegion(reg, 16, 0, 16, 16);
//    static cTextureRegion reg2 = cTextureRegion(*p_tex2);


    glEnable(GL_ALPHA_TEST) ;
    glAlphaFunc(GL_GREATER, 0.1f);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);


    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
//    ImmediateRenderTexturePos2Dim2(*p_tex, 0.0, 0.0f, 1.0f, 1.0f);

    batch.Begin();
//        batch.DrawTexture(*p_tex2, 0.0f, 3.0f, 1.0f, 1.0f);
        if (test) batch.DrawTexture(reg2, 0.0f, 1.0f, 4.0f, 1.0f);
//        batch.DrawTexturePos2Dim2Origin2Scale2Rot(reg, 0.0f, 0.0f, 2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 45.0f);

    batch.End();
}

void cPlayState::HandleInput(CORE::cGame* game)
{
    CORE::Input& input = game->GetInput();

    if (input.GetKeyState(SDLK_ESCAPE)) game->EndGame();
    if (input.OnKeyDown(SDLK_a)) { test = !test;}
    if (input.OnKeyDown(SDLK_b)) {
        STATE::cGameTransition* trans = game->transition_factory.CreateObject("trans");
        STATE::iGameState* newstate = game->state_factory.CreateObject("play");
        STATE::iGameState* const oldstate = game->GetStateManager().GetCurrent();

        trans->SetOldAndNewState(oldstate, newstate);
        game->GetStateManager().ReplaceStateUsingTransition(newstate, trans);
    }

}
