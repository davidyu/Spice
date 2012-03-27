#include "SDL/SDL.h"

#include "CORE_cGame.hpp"
#include "cGenericFactory.hpp"
#include "STATE_iGameState.hpp"
#include "demo_cPlayState.hpp"


/*temp*/ #include <iostream>
         #include <cassert>

using namespace CORE;
using namespace STATE;

cGame::cGame()
{
}

cGame::~cGame()
{
    //dtor
}

bool cGame::Initialise()
{
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

    m_input.Initialise();

    cGenericFactory<iGameState> state_factory; // FIXME:Should be declared elsewhere

    state_factory.RegisterClass("game", cPlayState::CreateInstance);
    m_state_manager.PushState(state_factory.CreateObject("game"));

}

bool cGame::Terminate()
{
    m_running = false;
}

void cGame::MainLoop()
{
    iGameState* state;
    float delta, percent_tick; // Dummy vars for now; substitute timer values in later

    while (m_running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                Terminate();
            }
        }
        // Update Input-- set old keystates and current ones
        m_input.Tick();

        // Game Loop
        state = m_state_manager.GetCurrent();
        /*DEBUG*/assert(state!=0);
        state->Update(this, delta);
        state->Render(percent_tick);
    }
}

CORE::Input& cGame::GetInput()
{
    return m_input;
}
cGameStateManager& cGame::GetStateManager()
{
    return m_state_manager;
}


