#ifndef CGAME_H
#define CGAME_H

#include "CORE_iApplication.hpp"
#include "CORE_Input.hpp"
#include "CORE_cTimer.hpp"
#include "STATE_cGameStateManager.hpp"

namespace CORE
{

class cGame : public iApplication
{
    public:
                                    cGame();
        virtual                     ~cGame();
        /*temp*/ static cGame*      Create() { return new cGame; }
        bool                        Initialise();
        bool                        Terminate();
        void                        MainLoop();
        void                        EndGame();

        CORE::Input&                GetInput();
        STATE::cGameStateManager&   GetStateManager();

    protected:
        bool m_running;
        STATE::cGameStateManager    m_state_manager;
        CORE::Input                 m_input;
        CORE::cTimer                m_timer;
};

}

#endif // CGAME_H
