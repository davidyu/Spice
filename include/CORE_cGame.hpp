#ifndef CGAME_H
#define CGAME_H

#include "CORE_iApplication.hpp"
#include "STATE_cGameStateManager.hpp"

namespace CORE
{

class cGame : public iApplication
{
    public:
        cGame();
        virtual ~cGame();
        /*temp*/ static cGame* Create() { return new cGame; }
        virtual bool Initialise();
        virtual bool Terminate();
        virtual void MainLoop();

    protected:
        bool m_running;
        cGameStateManager m_state_manager;
};

}

#endif // CGAME_H
