#ifndef INPUT_H
#define INPUT_H

// Headers
#include <algorithm>
#include "SDL/SDL.h"
#include "CORE_keycodes.hpp"

namespace
{
    const unsigned int LAST_KEY = SDLK_z;
}

namespace CORE
{

class Input
{
    public:
                    Input()                         { }
                    ~Input()                        { }
    void            Initialise()
    {
        std::fill(m_old_keystate, m_old_keystate+HAR_LAST, 0);
        std::fill(m_keystate, m_keystate+HAR_LAST, 0);
    }
    void            Tick()
    {
        std::copy(m_keystate, m_keystate+HAR_LAST, m_old_keystate);
        std::copy(SDL_GetKeyboardState(0), SDL_GetKeyboardState(0)+HAR_LAST, m_keystate);

        m_old_mousestate    = m_mousestate;
        m_old_xmouse        = m_xmouse;
        m_old_ymouse        = m_ymouse;
        m_mousestate        = SDL_GetMouseState(&m_xmouse, &m_ymouse);

    }

//    Uint8*          get_keystate()                  { return m_keystate; }
//    Uint8*          get_old_keystate()              { return m_old_keystate; }
    bool            GetKeyState(int key)            { return m_keystate[key]; }
    bool            OnKeyDown(int key)              { return (m_keystate[key] && !m_old_keystate[key]); }
    bool            OnKeyUp(int key)                { return (!m_keystate[key] && m_old_keystate[key]); }
    bool            OnMouseButtonDown(int b)        { return ((m_mousestate&SDL_BUTTON(b)) && !(m_old_mousestate&SDL_BUTTON(b))); }
    bool            OnMouseButtonUp(int b)          { return (!(m_mousestate&SDL_BUTTON(b)) && (m_old_mousestate&SDL_BUTTON(b))); }
    void            GetMousePos(int& x, int& y)     { x = m_xmouse; y = m_ymouse; }
    void            GetMouseDelta(int& x, int& y)   { x = m_xmouse-m_old_xmouse; y = m_ymouse-m_old_ymouse; }

    protected:

    Uint8           m_old_keystate[HAR_LAST];
    Uint8           m_keystate[HAR_LAST];
    Uint8           m_old_mousestate;
    Uint8           m_mousestate;
    int             m_old_xmouse, m_old_ymouse;
    int             m_xmouse, m_ymouse;
}; // class Input

} // namespace CORE

#endif // INPUT_H
