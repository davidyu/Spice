#include "CORE_Input.hpp"

using namespace CORE;

void Input::HandleEvent(const SDL_Event& event)
{
    switch(event.type)
    {
        case SDL_KEYDOWN:
            m_Keystates[event.key.keysym.sym] = 'd';
            m_RecentKeys.push_back(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            m_Keystates[event.key.keysym.sym] = 'u';
            m_RecentKeys.push_back(event.key.keysym.sym);
            break;
        case SDL_MOUSEMOTION:
            m_MouseX = event.motion.x;
            m_MouseY = event.motion.y;
            break;
        case SDL_MOUSEBUTTONUP:
                //do input core stuff here
            break;
        case SDL_MOUSEBUTTONDOWN:
                //do input core stuff here
            break;
        default:
            break;
    }
}

void Input::UpdateAll()
{
    bool keyFound = false;

    for (std::map<int, char>::iterator it = m_Keystates.begin(); it != m_Keystates.end(); ++it) {
        keyFound = false;

        if (it->second == 'u') {
            for (int i=0; i<m_RecentKeys.size(); ++i) {
                if (m_RecentKeys[i] == it->first) {
                    keyFound = true;
                    break;
                }
            }
            if (!keyFound) {
                it->second = 'n';
            }
        } else if(it->second == 'd') {
            for (int i=0; i<m_RecentKeys.size(); ++i) {
                if(m_RecentKeys[i] == it->first) {
                    keyFound = true;
                    break;
                }
            }
            if ( !keyFound ) {
                it->second = 'h';
            }
        }
    }
    m_RecentKeys.clear();
}
