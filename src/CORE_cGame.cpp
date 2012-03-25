#include "SDL/SDL.h"

#include "CORE_cGame.hpp"
#include "STATE_iGameState.hpp"

/*temp*/ #include <iostream>


using namespace CORE;

cGame::cGame()
{
    //ctor
}

cGame::~cGame()
{
    //dtor
}

bool cGame::Initialise()
{
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
}

bool cGame::Terminate()
{

}

void cGame::MainLoop()
{
    iGameState* state;
    float delta, percent_tick; // Dummy vars for now; substitute timer values in later

    while (m_running)
    {
        state = m_state_manager.GetCurrent(); // ERROR: State is NULL
        state->Update(this, delta);
        state->Render(percent_tick);

        m_running = false; // Temp statement to make program exit
    }
}
