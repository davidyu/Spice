#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>
#include "demo_cPlayState.hpp"
#include "CORE_cGame.hpp"
#include "GFX_cImage.hpp"
#include "GFX_cTexture.hpp"
#include "GFX_G2D_cTextureRegion.hpp"
#include "GFX_G2D_cSpriteBatch.hpp"
#include "GFX_G2D_cAnimation.hpp"
#include "GFX_cTextureRegistry.hpp"
#include "GFX_GfxHelper.hpp"

    #include <iostream>

using namespace GFX;
using namespace GFX::G2D;

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

Mix_Chunk* snd;
cTexture* p_tex;
cTexture* p_tex2;
bool cPlayState::OnEnter()
{
    p_tex = new cTexture("art/sea.png");
    p_tex2= new cTexture("art/light.png");
    p_tex->RegisterGL();
    p_tex2->RegisterGL();


//    cTextureRegistry::RegisterTexture("tiles", p_tex);
//    cTextureRegistry::RegisterTexture("try", p_tex2);

//    static cImage img("art/pixelmap.png");
//    std::cout << "starting\n";
//    for (int j=0; j<img.GetHeight(); ++j) {
//        for (int i=0; i<img.GetWidth(); ++i) {
//            std::cout << std::hex << ((img.GetPixel(i, j)& 0xffffff00) >> 8) << ", ";
//        }
//        std::cout << "\n";
//    }

    snd = Mix_LoadWAV( "sounds/explo1.wav" );
    if (snd == 0) std::cout << "BADDDD";
    Mix_PlayChannelTimed( -1, snd, 1, 400);
//    Mix_PlayMusic(snd, 1);

    return true;
}
bool cPlayState::OnExit()
{
    Mix_FreeChunk(snd);
}
void cPlayState::Pause() {}
void cPlayState::Resume() {}




void cPlayState::Update(CORE::cGame* game, float delta)
{
    if (game->GetInput().GetKeyState(HAR_ESCAPE)) game->EndGame();
}




void cPlayState::Render(CORE::cGame* game, float percent_tick)
{
//    SDL_Rect viewport, temp_rect;
//    SDL_Renderer* renderer = game->GetRenderer();
//
//    SDL_RenderGetViewport(renderer, &viewport);
//
//    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

    static G2D::cSpriteBatch batch = G2D::cSpriteBatch();

    static cTextureRegion reg = cTextureRegion(*p_tex);
    static cTextureRegion reg2 = cTextureRegion(*p_tex2);

    glClearColor (0.0, 0.0, 0.0, 0.0);
//    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
    glEnable(GL_ALPHA_TEST) ;
    glAlphaFunc(GL_GREATER, 0.1f);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    ImmediateRenderTexturePos2Dim2(reg2, 0.0, 0.0f, 1.0f, 1.0f);

//    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
    ImmediateRenderTexturePos2Dim2(reg, -3.0, -3.0f, 20.0f, 40.0f);

    batch.Begin();
//        batch.DrawTexture(*p_tex2, 0.0f, 3.0f, 1.0f, 1.0f);
//        batch.DrawTexture(reg, 0.0f, 0.0f, 1.0f, 1.0f);
//        batch.DrawTexturePos2Dim2Origin2Scale2Rot(reg, 0.0f, 0.0f, 2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 45.0f);

    batch.End();

    glMatrixMode(GL_PROJECTION);
//    glTranslatef(0.0f, -0.01f, 0.0f);
//    glRotatef(0.1, 1.0, 1.0, 1.0);
}

void cPlayState::HandleInput() {}
