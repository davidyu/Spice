#ifndef CGAMESTATEMANAGER_H
#define CGAMESTATEMANAGER_H

#include <stack>

namespace STATE
{

class iGameState;
class cGameTransition;

class cGameStateManager
{
    public:
        cGameStateManager();
        virtual ~cGameStateManager();

        // Exchanges the current state with a new one, using a transition state if provided. Returns the old state.
        // WARNING: If transition is provided, a full clone of new_state will be allocated and deleted (performance issue?)
        iGameState* SwapState(iGameState* new_state, cGameTransition* transition=0);

        // WARNING: If transition is provided, a full clone of new_state will be allocated and deleted (performance issue?)
        void PushState(iGameState* new_state, cGameTransition* transition=0);

        // WARNING: If transition is provided, a full clone of new_state will be allocated and deleted (performance issue?)
        iGameState* PopState(cGameTransition* transition=0);

        iGameState* GetCurrent();

        // Performs each state's OnExit, and deletes the state.
        void Clear();
    private:
        // Methods
        // Pops the current state and deletes the state from heap
        void DeleteTop();

        // Members
        std::stack<iGameState*> m_states;

}; // class cGameStateManager

} // namespace STATE

#endif // CGAMESTATEMANAGER_H
