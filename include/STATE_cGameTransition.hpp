// Class from which all transition classes inherit from.
#ifndef CGAMETRANSITION_H
#define CGAMETRANSITION_H

#include "CORE_cGame.hpp"

namespace CORE
{
    class cGame;
}

namespace STATE
{

    class cGameTransition : public iGameState
    {
        public:
                            cGameTransition() : mp_old_state(0), mp_new_state(0) {}
            virtual         ~cGameTransition() {}

            virtual bool    OnEnter() {}
            virtual bool    OnExit()
                            {
                                // Must delete old state since GameStateManager does not know
                                // when the transition is done with the old state
                                DELETESINGLE(mp_old_state);
                            }
            virtual void    Pause() {}
            virtual void    Resume() {}

            virtual void    Update(CORE::cGame* game, float delta)
                            {
                                Finish(); // Dummy transition finishes right away
                            }
            virtual void    Render(float percent_tick) {}

            void            HandleInput() {}

            void            SetOldAndNewState(iGameState* old_s, iGameState* new_s)
                            {
                                mp_old_state = old_s;
                                mp_new_state = new_s;

                            }
            void            Finish()
                            {
                                game->GetStateManager().PopState();
                            }
        protected:
            iGameState*             mp_old_state;
            iGameState*             mp_new_state;

    }; // class cGameTransition

} // namespace STATE

#endif // CGAMETRANSITION_H
