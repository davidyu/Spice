#include <SDL2/SDL_opengl.h>
#include "demo_cPlayState.hpp"
#include "CORE_cGame.hpp"
#include "GFX_cTexture.hpp"
#include "GFX_G2D_cTextureRegion.hpp"
#include "GFX_G2D_cSpriteBatch.hpp"

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

cTexture* p_tex = 0;

bool cPlayState::OnEnter()
{
    p_tex = new cTexture("art/tilez.png");
    p_tex->RegisterGL();
}
bool cPlayState::OnExit()
{
    delete p_tex;
    p_tex = 0;
}
void cPlayState::Pause() {}
void cPlayState::Resume() {}

void cPlayState::Update(CORE::cGame* game, float delta)
{
    if (game->GetInput().GetKeyState(HAR_ESCAPE)) game->EndGame();
}
static void
Rander()
{
    static float color[8][3] = {
        {1.0, 1.0, 0.0},
        {1.0, 0.0, 0.0},
        {0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 1.0, 1.0},
        {1.0, 1.0, 1.0},
        {1.0, 0.0, 1.0},
        {0.0, 0.0, 1.0}
    };
    static float cube[8][3] = {
        {0.5, 0.5, -0.5},
        {0.5, -0.5, -0.5},
        {-0.5, -0.5, -0.5},
        {-0.5, 0.5, -0.5},
        {-0.5, 0.5, 0.5},
        {0.5, 0.5, 0.5},
        {0.5, -0.5, 0.5},
        {-0.5, -0.5, 0.5}
    };

    /* Do our drawing, too. */

    glBegin(GL_QUADS);
#define SHADED_CUBE
#ifdef SHADED_CUBE
    glColor3fv(color[0]);
    glVertex3fv(cube[0]);
    glColor3fv(color[1]);
    glVertex3fv(cube[1]);
    glColor3fv(color[2]);
    glVertex3fv(cube[2]);
    glColor3fv(color[3]);
    glVertex3fv(cube[3]);

    glColor3fv(color[3]);
    glVertex3fv(cube[3]);
    glColor3fv(color[4]);
    glVertex3fv(cube[4]);
    glColor3fv(color[7]);
    glVertex3fv(cube[7]);
    glColor3fv(color[2]);
    glVertex3fv(cube[2]);

    glColor3fv(color[0]);
    glVertex3fv(cube[0]);
    glColor3fv(color[5]);
    glVertex3fv(cube[5]);
    glColor3fv(color[6]);
    glVertex3fv(cube[6]);
    glColor3fv(color[1]);
    glVertex3fv(cube[1]);

    glColor3fv(color[5]);
    glVertex3fv(cube[5]);
    glColor3fv(color[4]);
    glVertex3fv(cube[4]);
    glColor3fv(color[7]);
    glVertex3fv(cube[7]);
    glColor3fv(color[6]);
    glVertex3fv(cube[6]);

    glColor3fv(color[5]);
    glVertex3fv(cube[5]);
    glColor3fv(color[0]);
    glVertex3fv(cube[0]);
    glColor3fv(color[3]);
    glVertex3fv(cube[3]);
    glColor3fv(color[4]);
    glVertex3fv(cube[4]);

    glColor3fv(color[6]);
    glVertex3fv(cube[6]);
    glColor3fv(color[1]);
    glVertex3fv(cube[1]);
    glColor3fv(color[2]);
    glVertex3fv(cube[2]);
    glColor3fv(color[7]);
    glVertex3fv(cube[7]);
#endif /* SHADED_CUBE */

    glEnd();
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

    static cTextureRegion reg = cTextureRegion(*p_tex, 64, 0, 128, 64);
    static cTextureRegion reg2 = cTextureRegion(reg, 0.5f, 0.0f, 1.0f, 1.0f);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    Rander();
//    RenderTexture(reg2);

    batch.Begin();
        batch.DrawTexture(reg2, -2.0f, -2.0f, 1.0f, 1.0f);
        batch.DrawTextureRotScale(reg2, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 2.0f, 2.0f);
    batch.End();

//    glMatrixMode(GL_PROJECTION);
//    glRotatef(0.1, 1.0, 1.0, 1.0);
}

void cPlayState::HandleInput() {}

