#include <SDL2/SDL_opengl.h>
#include "demo_cPlayState.hpp"
#include "CORE_cGame.hpp"
#include "GFX_cImage.hpp"
#include "GFX_cTexture.hpp"
#include "GFX_G2D_cTextureRegion.hpp"
#include "GFX_G2D_cSpriteBatch.hpp"
#include "GFX_G2D_cAnimation.hpp"
#include "GFX_cTextureRegistry.hpp"

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



bool cPlayState::OnEnter()
{
    cTexture p_tex("art/tilez.png");
    cTexture p_tex2("art/try.jpg");
    p_tex.RegisterGL();
    p_tex2.RegisterGL();

    cTextureRegistry::RegisterTexture("tiles", p_tex);
    cTextureRegistry::RegisterTexture("try", p_tex2);

    static cImage img("art/pixelmap.png");
    std::cout << "starting\n";
    for (int j=0; j<img.GetHeight(); ++j) {
        for (int i=0; i<img.GetWidth(); ++i) {
            std::cout << std::hex << ((img.GetPixel(i, j)& 0xffffff00) >> 8) << ", ";
        }
        std::cout << "\n";
    }
}
bool cPlayState::OnExit()
{
}
void cPlayState::Pause() {}
void cPlayState::Resume() {}

void cPlayState::Update(CORE::cGame* game, float delta)
{
    if (game->GetInput().GetKeyState(HAR_ESCAPE)) game->EndGame();
}


void RenderTexture(const cTextureWrapper& tex)
{
    glBindTexture(GL_TEXTURE_2D, tex.GetID());               // Select Our Texture
    glBegin(GL_QUADS);
		// Front Face
		glTexCoord2f(tex.GetU2(), tex.GetV2()); glVertex3f( 2.0f,  2.0f,  1.0f);
		glTexCoord2f(tex.GetU(), tex.GetV2()); glVertex3f(-2.0f,  2.0f,  1.0f);
		glTexCoord2f(tex.GetU(), tex.GetV()); glVertex3f(-2.0f, -2.0f,  1.0f);
		glTexCoord2f(tex.GetU2(), tex.GetV()); glVertex3f( 2.0f, -2.0f,  1.0f);
	glEnd();
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

    static cTextureRegion reg = cTextureRegion(cTextureRegistry::GetTexture("tiles"), 64, 0, 128, 64);
    static cTextureRegion reg2 = cTextureRegion(cTextureRegistry::GetTexture("try"));

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    RenderTexture(reg2);

    batch.Begin();
//        batch.DrawTexture(*p_tex2, 0.0f, 3.0f, 1.0f, 1.0f);
        batch.DrawTexture(reg2, -2.0f, -2.0f, 1.0f, 1.0f);
        batch.DrawTextureRotScale(reg, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 2.0f, 2.0f);

    batch.End();

//    glMatrixMode(GL_PROJECTION);
//    glRotatef(0.1, 1.0, 1.0, 1.0);
}

void cPlayState::HandleInput() {}
