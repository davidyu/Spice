#include <iostream>
#include "CORE_cGame.hpp"

using namespace CORE;

iApplication* create() { return new cGame(); }

int main()
{
    iApplication* game = new cGame();

    game->Initialise();
    game->MainLoop();
    game->Terminate();

    return 0;
}
