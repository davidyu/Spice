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
#include "GFX_TextureUtilities.hpp"
#include "GFX_MotionBlur.hpp"

    #include <iostream>
    using namespace std;

#define WINDOW_WIDTH game->GetSDLState().window_w
#define WINDOW_HEIGHT game->GetSDLState().window_h


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
bool cPlayState::OnEnter(CORE::cGame* game)
{
    cout << "Entering State\n";
    if (!p_tex) {
        p_tex = new cTexture("art/tilez.png");
        p_tex->RegisterGL();
    }
    if (!m_pMotionTex) {
        m_pMotionTex = new cTextureWrapper();
        CreateMotionBlurTexture(0, 0, *m_pMotionTex);
    }

    test = false;



    return true;
}
bool cPlayState::OnExit(CORE::cGame* game)
{
    DELETESINGLE(p_tex);
    cout << "Leaving state\n";

}
void cPlayState::Pause(CORE::cGame* game) {}
void cPlayState::Resume(CORE::cGame* game) {}




void cPlayState::Update(CORE::cGame* game, float delta)
{
    HandleInput(game);
}

void cPlayState::Render(CORE::cGame* game, float percent_tick)
{
    static G2D::cSpriteBatch batch = G2D::cSpriteBatch();

    static cTextureRegion reg = cTextureRegion(*p_tex);
    static cTextureRegion reg2 = cTextureRegion(reg, 16, 0, 16, 16);
    static float rot = 0.0f;

    static GLuint texID;

    rot += percent_tick*0.1f;
    rot = fmod(rot, 360.0f);


    glEnable(GL_ALPHA_TEST) ;
    glAlphaFunc(GL_GREATER, 0.1f);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,
			GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, m_pMotionTex->GetTextureWidth(), m_pMotionTex->GetTextureHeight());

    ImmediateRenderTexturePos2Dim2Origin2Scale2Rot(*p_tex, 0.0, 0.0f, 400.0f, 400.0f, 200.0f, 200.0f, 1.0f, 1.0f, rot);
//    ImmediateRenderTexturePos2Dim2(*p_tex, 0.0, 0.0f, 400.0f, 400.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 0.9f);
    ImmediateRenderTexturePos2Dim2Origin2Scale2Rot(*m_pMotionTex, 0.0f, 0.0f, 640.0f, 480.0f, 320.0f, 240.0f, 1.0f, -1.0f, 0.0f);

    glBindTexture(GL_TEXTURE_2D, m_pMotionTex->GetID());
	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 0, 0,
    512, 512, 0);
    glBindTexture(GL_TEXTURE_2D, 0);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);



//    glPushMatrix();
////        glScalef(1.0f, -1.0f, 1.0f);
//        glTranslatef(100.0f, 0.0f, 0.0f);
//
//    glPopMatrix();

    batch.Begin();
//        batch.DrawTexture(*p_tex2, 0.0f, 3.0f, 1.0f, 1.0f);
//    batch.DrawTexture(reg, 0.0f, 0.0f, 640.0f, 480.0f);
//        batch.DrawTexturePos2Dim2Origin2Scale2Rot(reg, 0.0f, 0.0f, 2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 45.0f);

    batch.End();

//    glEnable(GL_DEPTH_TEST);

//    glMatrixMode(GL_MODELVIEW);
//    glTranslatef(-320.0f,-240.0f, 0.0f);
//    glRotatef(3.0, 1.0, 1.0, 1.0);
//    glTranslatef(320.0f,240.0f, 0.0f);
}

void cPlayState::HandleInput(CORE::cGame* game)
{
    CORE::Input& input = game->GetInput();

    if (input.GetKeyState(SDLK_ESCAPE)) game->EndGame();
    if (input.OnKeyDown(SDLK_a)) { test = !test;}
    if (input.OnMouseButtonDown(SDL_BUTTON_LEFT)) { test = !test;}
    if (input.OnKeyDown(SDLK_b)) {
        STATE::cGameTransition* trans = game->transition_factory.CreateObject("transSquareSpin");
        STATE::iGameState* newstate = game->state_factory.CreateObject("play");

        game->GetStateManager().ReplaceStateUsingTransition(newstate, trans);
    }
    float x, y;
<<<<<<< HEAD
//    input.GetJoyExtentIDWhichExtent2(0, 0, x, y);
//    if (input.OnJoyButtonDown(0, 5)) {
//        cout << x << ", " << y << endl;
//    }


=======
    input.GetJoyExtentIDWhichExtent2(0, 0, x, y);
    if (input.OnJoyButtonDown(0, 5)) {
        cout << x << ", " << y << endl;
    }
>>>>>>> 5a24c11cdd0f63ac9ab317d9334e7eeeb161cd38
}
