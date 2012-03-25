#include <iostream>
#include "cGenericFactory.hpp"
#include "CORE_cGame.hpp"

using namespace CORE;

iApplication* create() { return new cGame(); }

int main()
{
    cGenericFactory<iApplication> stateFactory;

    stateFactory.RegisterClass("game", create);

    iApplication* game = stateFactory.CreateObject("game");
    game->Initialise();
    game->MainLoop();
    game->Terminate();

    return 0;
}
