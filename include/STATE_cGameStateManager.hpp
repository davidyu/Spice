#ifndef CGAMESTATEMANAGER_H
#define CGAMESTATEMANAGER_H

#include <stack>

class iGameState;

class cGameStateManager
{
    public:
        cGameStateManager();
        virtual ~cGameStateManager();

        // Exchanges the current state with a new one, using a transition state if provided. Returns the old state.
        iGameState* SwapState(iGameState* new_state, iGameState* transition=0);

        void PushState(iGameState* new_state, iGameState* transition=0);

        iGameState* PopState(iGameState* transition=0);

        iGameState* GetCurrent();
    private:
        std::stack<iGameState*> m_states;
};

#endif // CGAMESTATEMANAGER_H
