/**
 *
 */

#include "STATE_cTransSquareSpin.hpp"

#include <GL/glu.h>
#include "CORE_cGame.hpp"
#include "MATH_Math.hpp"

using namespace STATE;
using namespace MATH;

namespace
{
        struct Quad
        {
            Vec2f v[4];
        };

        Quad square;
}

cTransSquareSpin::cTransSquareSpin()
: m_PercentDone(0.0f)
, m_AnimSpeed(2.0f)
{
    //ctor
}

cTransSquareSpin::~cTransSquareSpin()
{
    //dtor
}

bool cTransSquareSpin::OnEnter(CORE::cGame* game)
{
    glViewport(0, 0, game->GetSDLState().window_w, game->GetSDLState().window_h);
    glMatrixMode(GL_PROJECTION);								// Select The Projection Matrix
    glLoadIdentity();											// Reset The Projection Matrix
    // Set Up Ortho Mode To Fit 1/4 The Screen (Size Of A Viewport)
    glOrtho(0, game->GetSDLState().window_w, game->GetSDLState().window_h, 0, -10.0, 10.0);

    glMatrixMode(GL_MODELVIEW);								// Select The Projection Matrix
    glLoadIdentity();

    m_PercentDone = 0.0f;
}

bool cTransSquareSpin::OnExit(CORE::cGame* game)
{
    // Must delete old state since GameStateManager does not know
    // when the transition is done with the old state
    m_pOldState->OnExit(game);
    DELETESINGLE(m_pOldState);
    return true;
}

void cTransSquareSpin::Update(CORE::cGame* game, float delta)
{
    square.v[0] = Vec2f(1.0f, 1.0f);
    square.v[1] = Vec2f(-1.0f, 1.0f);
    square.v[2] = Vec2f(-1.0f, -1.0f);
    square.v[3] = Vec2f(1.0f, -1.0f);


    for (int i=0; i<4; ++i) {
        square.v[i] *= 32.0f;
//        square.v[i].Rotate(m_PercentDone*180.0f);
        square.v[i] += Vec2f(320.0f, 320.0f);
    }

//    m_PercentDone += delta * m_AnimSpeed;
}

void cTransSquareSpin::Render(CORE::cGame* game, float percent_tick)
{
    m_pOldState->Render(game, percent_tick);

    Vec2f offset[4] = { Vec2f(0.0f, 0.0f), Vec2f(64.0f, 0.0f), Vec2f(64.0f, 64.0f), Vec2f(0.0f, 64.0f) };
    glBindTexture(GL_TEXTURE_2D, 0);
    glBegin(GL_QUADS);
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        for (int i=0; i<4; ++i) {
            glVertex3f(square.v[0].x + offset[i].x, square.v[0].y+ offset[i].y, 0.0f);
            glVertex3f(square.v[1].x + offset[i].x, square.v[1].y+ offset[i].y, 0.0f);
            glVertex3f(square.v[2].x + offset[i].x, square.v[2].y+ offset[i].y, 0.0f);
            glVertex3f(square.v[3].x + offset[i].x, square.v[3].y+ offset[i].y , 0.0f);
        }
    glEnd();

}
