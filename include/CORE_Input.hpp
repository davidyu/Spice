#ifndef INPUT_H
#define INPUT_H

// Headers
#include <algorithm>
#include "SDL2/SDL.h"
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
    inline void            Update()
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
    inline bool     GetKeyState(int key) const           { return m_keystate[key]; }
    inline bool     OnKeyDown(int key) const             { return (m_keystate[key] && !m_old_keystate[key]); }
    inline bool     OnKeyUp(int key) const               { return (!m_keystate[key] && m_old_keystate[key]); }
    inline bool     OnMouseButtonDown(int b) const       { return ((m_mousestate&SDL_BUTTON(b)) && !(m_old_mousestate&SDL_BUTTON(b))); }
    inline bool     OnMouseButtonUp(int b) const         { return (!(m_mousestate&SDL_BUTTON(b)) && (m_old_mousestate&SDL_BUTTON(b))); }
    inline void     GetMousePos(int& x, int& y) const    { x = m_xmouse; y = m_ymouse; }
    inline void     GetMouseDelta(int& x, int& y) const  { x = m_xmouse-m_old_xmouse; y = m_ymouse-m_old_ymouse; }

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
