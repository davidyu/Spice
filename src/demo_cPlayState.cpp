#include "demo_cPlayState.hpp"
#include "CORE_cGame.hpp"

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

bool cPlayState::OnEnter() {}
bool cPlayState::OnExit() {}
void cPlayState::Pause() {}
void cPlayState::Resume() {}

void cPlayState::Update(CORE::cGame* game, float delta)
{
    if (game->GetInput().GetKeyState(HAR_ESCAPE)) game->EndGame();
}

void cPlayState::Render(CORE::cGame* game, float percent_tick)
{
    SDL_Rect viewport, temp;
    SDL_Renderer* renderer = game->GetRenderer();

    SDL_RenderGetViewport(renderer, &viewport);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    temp.x = temp.y = 0;
    temp.w = temp.h = 50;

    SDL_RenderFillRect(renderer, &temp);
}

void cPlayState::HandleInput() {}

