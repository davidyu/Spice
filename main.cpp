#include <iostream>
#include "CORE_cGame.hpp"

using namespace CORE;

// Main function must have these params for SDL... kinda lame for encapsulation here..
int main(int argc, char* args[])
{
    iApplication* game = new cGame();

    game->Initialise();
    game->MainLoop();
    game->Terminate();

    delete game;

    return 0;
}
