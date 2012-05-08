// Class from which all transition classes inherit from.
#ifndef CGAMETRANSITION_H
#define CGAMETRANSITION_H

#include "CORE_cGame.hpp"
//#include "global_inc.hpp"
#include "memory_macros.h"

namespace CORE
{
    class cGame;
}

namespace STATE
{

    class cGameTransition : public iGameState
    {
        public:
                            cGameTransition() : m_pOldState(0), m_pNewState(0) {}
            virtual         ~cGameTransition() {}

            static          STATE::cGameTransition* CreateInstance() { return new cGameTransition; }
            virtual STATE::iGameState* Clone() {}

            virtual bool    OnEnter() {}
            virtual bool    OnExit()
                            {
                                // Must delete old state since GameStateManager does not know
                                // when the transition is done with the old state
                                DELETESINGLE(m_pOldState);
                                return true;
                            }
            virtual void    Pause() {}
            virtual void    Resume() {}

            virtual void    Update(CORE::cGame* game, float delta)
                            {
                                Finish(game); // Dummy transition finishes right away
                            }

            virtual void    Render(CORE::cGame* game, float percent_tick) {}

            void            HandleInput() {}

            void            SetOldAndNewState(iGameState* old_s, iGameState* new_s)
                            {
                                m_pOldState = old_s;
                                m_pNewState = new_s;
                            }

            void            Finish(CORE::cGame* game)
                            {
                                game->GetStateManager().PopState();
                            }
        protected:
            iGameState*             m_pOldState;
            iGameState*             m_pNewState;

    }; // class cGameTransition

} // namespace STATE

#endif // CGAMETRANSITION_H
