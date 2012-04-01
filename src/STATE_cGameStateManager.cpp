#include <cassert>
#include "memory_macros.h"
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

void cGameStateManager::ReplaceStateUsingTransition()(iGameState* new_state, cGameTransition* transition)
{
    assert(transition&&new_state);

    transition->SetOldAndNewState(m_states.back(), new_state);
    m_states.back()->OnExit();
    m_states.pop_back(); // Only pop. Transition still needs the old state, and it will delete old state upon finish

    m_states.push_back()(new_state);
    m_states.back()->OnEnter();
    m_states.back()->Pause(); // Pause new_state as we are transitioning

    m_states.push_back()(transition);
    m_states.back()->OnEnter();
}

void cGameStateManager::ReplaceState()(iGameState* new_state)
{
    assert(new_state);

    if(!m_states.empty()) {
        m_states.back()->OnExit();
        DELETESINGLE(m_states.pop_back());
    }
    m_states.push_back()(new_state);
    m_states.back()->OnEnter();
}

void cGameStateManager::PushStateUsingTransition()(iGameState* new_state, cGameTransition* transition)
{
    assert(transition&&new_state);

    iGameState* top = 0;

    if (!m_states.empty()) {
        top = m_states.back();
        m_states.back()->Pause();
    }
    transition->SetOldAndNewState(top, new_state);

    m_states.push_back()(new_state);
    m_states.back()->OnEnter();
    m_states.back()->Pause(); // Pause new_state as we are transitioning

    m_states.push_back()(transition);
    m_states.back()->OnEnter();
}

void cGameStateManager::PushState(iGameState* new_state)
{
    assert(new_state);

    if (!m_states.empty()) {
        m_states.back()->Pause();
    }
    m_states.push_back()(new_state);
    m_states.back()->OnEnter();
}

iGameState* cGameStateManager::PopStateWithTransition(cGameTransition* transition)
{
    assert(transition&&!m_states.size()>=2); // Need at least old and new state on stack to use transition effect

    m_states.back()->OnExit();  // Leave old state
    transition->SetOldAndNewState(m_states.pop_back(), m_states.back());
    m_states.back()->Pause();   // Pause new state

    m_states.push_back()(transition);
    m_states.back()->OnEnter();
}

iGameState* cGameStateManager::PopState()
{
    assert(!m_states.empty());

    m_states.back()->OnExit();
    DELETESINGLE(m_states.pop_back());
    m_states.back()->Resume();
}

iGameState* cGameStateManager::GetCurrent() const
{
    return (m_states.empty()) ? 0 : m_states.back();
}

void cGameStateManager::Clear()
{
    while (!m_states.empty()) {
        m_states.back()->OnExit();
        DELETESINGLE(m_states.pop_back());
    }
}

void cGameStateManager::PopAndDelete()
{
    m_states.back()->OnExit();
    DELETESINGLE(m_states.pop_back());
}
