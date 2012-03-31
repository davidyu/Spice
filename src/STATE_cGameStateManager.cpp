#include "STATE_cGameStateManager.hpp"
#include "STATE_iGameState.hpp"
#include "STATE_cGameTransition.hpp"

using namespace STATE;

cGameStateManager::cGameStateManager()
{
    //ctor
}

cGameStateManager::~cGameStateManager()
{
    Clear();
}

void cGameStateManager::SwapState(iGameState* new_state, cGameTransition* transition)
{
    // So ugly code T_T
    if (transition!=0) {
        transition->SetOldAndNewState(m_states.top()->Clone(), new_state->Clone());
    }
    if(!m_states.empty()) {
        DeleteTop();
    }
    m_states.push(new_state);
    m_states.top()->OnEnter();

    if (transition!=0) {
        m_states.top()->Pause(); // Pause new_state as we are transitioning
        m_states.push(transition);
        m_states.top()->OnEnter();
    }
}

void cGameStateManager::PushState(iGameState* new_state, cGameTransition* transition)
{
    // So ugly code T_T
    if (transition!=0) {
        transition->SetOldAndNewState(m_states.top()->Clone(), new_state->Clone());
    }
    if (!m_states.empty()) {
        m_states.top()->Pause();
    }
    m_states.push(new_state);
    m_states.top()->OnEnter();

    if (transition!=0) {
        m_states.top()->Pause(); // Pause new_state as we are transitioning
        m_states.push(transition);
        m_states.top()->OnEnter();
    }
}
iGameState* cGameStateManager::PopState(cGameTransition* transition)
{
    if (transition!=0) {
        iGameState* temp = m_states.top()->Clone();

        DeleteTop();
        transition->SetOldAndNewState(temp, m_states.top()->Clone());
    } else {
        DeleteTop();
    }
    if (!m_states.empty()) {
        m_states.top()->Resume();
    }
    if (transition!=0) {
        m_states.top()->Pause(); // Pause new_state as we are transitioning
        m_states.push(transition);
        m_states.top()->OnEnter();
    }
}

iGameState* cGameStateManager::GetCurrent() const
{
    return (m_states.empty()) ? 0 : m_states.top();
}

void cGameStateManager::Clear()
{
    while (!m_states.empty()) {
        DeleteTop();
    }
}

void cGameStateManager::DeleteTop()
{
    m_states.top()->OnExit();
    delete m_states.top();
    m_states.pop();
}
