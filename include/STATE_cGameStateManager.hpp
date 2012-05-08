#ifndef CGAMESTATEMANAGER_H
#define CGAMESTATEMANAGER_H

#include <vector>

namespace STATE
{

    class iGameState;
    class cGameTransition;

    class cGameStateManager
    {
        public:
                                cGameStateManager();
            virtual ~           cGameStateManager();

            void                ReplaceState(iGameState* new_state);
            void                ReplaceStateUsingTransition(iGameState* new_state, cGameTransition* transition);

            void                PushState(iGameState* new_state);
            void                PushStateUsingTransition(iGameState* new_state, cGameTransition* transition);

            void                PopState();
            void                PopStateUsingTransition(cGameTransition* transition);

            iGameState*         GetCurrent() const;

            // Performs each state's OnExit, and deletes the state.
            void                ClearAll();

            // Intended for debug use
            int                 GetNumStates() const;
        private:

            // Members
            std::vector<iGameState*> m_states;

    }; // class cGameStateManager

} // namespace STATE

#endif // CGAMESTATEMANAGER_H
