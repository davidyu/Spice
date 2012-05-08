/* Include windows.h properly on Windows */
#if defined(WIN32) || defined(_WINDOWS)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#ifndef HELLO_MAGIC_MAIN
#  undef main
#endif


#include <iostream>
#include "CORE_cGame.hpp"
#include "STATE_iGameState.hpp"

#include "demo_cPlayState.hpp"
#include "STATE_cGameTransition.hpp"

using namespace CORE;

void RegisterStates()
{
    CORE::cGame::state_factory.RegisterClass("play", cPlayState::CreateInstance);
//
    cGame::transition_factory.RegisterClass("trans", STATE::cGameTransition::CreateInstance);
}

// Main function must have these params for SDL... kinda lame for encapsulation here..
int main(int argc, char* args[])
{
    RegisterStates();

    iApplication* game = new cGame();
    STATE::iGameState* state = cGame::state_factory.CreateObject("play");

    if (game->Initialise()) {
        dynamic_cast<cGame*>(game)->GetStateManager().PushState(state);
        game->MainLoop();
        game->Terminate();
    }


    delete game;

    return 0;
}
