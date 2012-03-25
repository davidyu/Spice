#ifndef DEMO_CPLAYSTATE_H
#define DEMO_CPLAYSTATE_H

#include "STATE_iGameState.hpp"

namespace CORE
{
    class cGame;
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

        void Update(CORE::cGame* game, float delta) {}
        void Render(float percent_tick) {}

        void HandleInput() {}
    private:
};

#endif // DEMO_CPLAYSTATE_H
