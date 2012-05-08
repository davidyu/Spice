// Based on Kore input by Sean Chapel
#ifndef INPUT_H
#define INPUT_H

// Headers
#include "global_inc.hpp"
//#include <map>
//#include <vector>
//#include "SDL2/SDL.h"
//#include "CORE_keycodes.hpp"

//namespace
//{
//    const unsigned int LAST_KEY = SDLK_z;
//}

namespace CORE
{

    class Input
    {
    public:
                        Input() : m_Keystates()                        { }
                        ~Input()                        { }

        void            Initialise() {}
//                        {
//                            std::fill(m_old_keystate, m_old_keystate+HAR_LAST, 0);
//                            std::fill(m_keystate, m_keystate+HAR_LAST, 0);
//                        }

        void            HandleEvent(const SDL_Event& event);
        void            UpdateAll();

        bool     GetKeyState(int key);
        bool     OnKeyDown(int key);
        bool     OnKeyUp(int key);
//        inline bool     OnMouseButtonDown(int b) const       { return ((m_mousestate&SDL_BUTTON(b)) && !(m_old_mousestate&SDL_BUTTON(b))); }
//        inline bool     OnMouseButtonUp(int b) const         { return (!(m_mousestate&SDL_BUTTON(b)) && (m_old_mousestate&SDL_BUTTON(b))); }
//        inline void     GetMousePos(int& x, int& y) const    { x = m_xmouse; y = m_ymouse; }
//        inline void     GetMouseDelta(int& x, int& y) const  { x = m_xmouse-m_old_xmouse; y = m_ymouse-m_old_ymouse; }

//        inline void     Update()
//                        {
//                            Uint8* keyboard_state = SDL_GetKeyboardState(0);
//
//                            std::copy(m_keystate, m_keystate+HAR_LAST, m_old_keystate);
//                            std::copy(keyboard_state, keyboard_state+HAR_LAST, m_keystate);
//
//                            m_old_mousestate    = m_mousestate;
//                            m_old_xmouse        = m_xmouse;
//                            m_old_ymouse        = m_ymouse;
//                            m_mousestate        = SDL_GetMouseState(&m_xmouse, &m_ymouse);
//
//                        }

        //    Uint8*          get_keystate()                  { return m_keystate; }
        //    Uint8*          get_old_keystate()              { return m_old_keystate; }
//        inline bool     GetKeyState(int key) const           { return m_keystate[key]; }
//        inline bool     OnKeyDown(int key) const             { return (m_keystate[key] && !m_old_keystate[key]); }
//        inline bool     OnKeyUp(int key) const               { return (!m_keystate[key] && m_old_keystate[key]); }
//        inline bool     OnMouseButtonDown(int b) const       { return ((m_mousestate&SDL_BUTTON(b)) && !(m_old_mousestate&SDL_BUTTON(b))); }
//        inline bool     OnMouseButtonUp(int b) const         { return (!(m_mousestate&SDL_BUTTON(b)) && (m_old_mousestate&SDL_BUTTON(b))); }
//        inline void     GetMousePos(int& x, int& y) const    { x = m_xmouse; y = m_ymouse; }
//        inline void     GetMouseDelta(int& x, int& y) const  { x = m_xmouse-m_old_xmouse; y = m_ymouse-m_old_ymouse; }

    private:
        std::map<int, char> m_Keystates;	        /**< Holds the state of the keys */
        std::vector<SDL_Keycode> m_RecentKeys;
        std::vector<char> m_MouseButtons;

        int m_MouseX;
        int m_MouseY;


//        Uint8           m_old_keystate[HAR_LAST];
//        Uint8           m_keystate[HAR_LAST];
//        Uint8           m_old_mousestate;
//        Uint8           m_mousestate;
//        int             m_old_xmouse, m_old_ymouse;
//        int             m_xmouse, m_ymouse;
    }; // class Input

    inline bool Input::GetKeyState(int key)
    { return (m_Keystates[key]=='h' || m_Keystates[key]=='d') ? true : false; }

    inline bool Input::OnKeyDown(int key)
    { return (m_Keystates[key]=='d') ? true : false; }

    inline bool Input::OnKeyUp(int key)
    { return (m_Keystates[key]=='u') ? true : false; }

} // namespace CORE

#endif // INPUT_H
