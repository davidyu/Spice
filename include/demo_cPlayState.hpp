#ifndef DEMO_CPLAYSTATE_H
#define DEMO_CPLAYSTATE_H

#include "STATE_iGameState.hpp"
//#include "CORE_Input.hpp"
/*temp*/#include <iostream>

namespace CORE
{
    class cGame;
    class Input;
}

//static STATE::iGameState* CreateInstance() {}

class cPlayState : public STATE::iGameState
{
    public:
        cPlayState() {}
        virtual ~cPlayState() {}

        static STATE::iGameState* CreateInstance() { return new cPlayState; }
        virtual STATE::iGameState* Clone() { return new cPlayState; } // Ideally this function should return a copy, not a blank instance

        bool OnEnter() {}
        bool OnExit() {}
        void Pause() {}
        void Resume() {}

        void Update(CORE::cGame* game, float delta)
        {
            if (game->GetInput().GetKeyState(HAR_ESCAPE)) game->EndGame();
        }
        void Render(float percent_tick) {}

        void HandleInput() {}
    private:
};

#endif // DEMO_CPLAYSTATE_H
