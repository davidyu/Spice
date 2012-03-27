#ifndef CTIMER_H
#define CTIMER_H

// Headers
#include "SDL/SDL.h"

namespace CORE
{

class CTimer
{
    public:
        //Initializes variables
                                CTimer()
                                    m_ticks_since_start(0),
                                    m_m_is_pausedticks(0),
                                    m_is_paused(false),
                                    m_is_started(false) {}

        virtual                 ~CTimer() {}

        //The various clock actions
        void                    Start()
                                {
                                        m_is_started = true;
                                        m_is_paused = false;
                                        m_ticks_since_start = SDL_GetTicks();
                                }
        void                    Stop()      { m_is_paused = m_is_started = false; }

        void                    Pause()
                                {
                                    if ((m_is_started == true) && (m_is_paused == false))
                                    {
                                        m_is_paused = true;
                                        m_ticks_since_pause = SDL_GetTicks() - m_ticks_since_start;
                                    }
                                }
        void                    Unpause()
                                {
                                    if(m_is_paused == true)
                                    {
                                        m_is_paused = false;
                                        m_ticks_since_start = SDL_GetTicks() - m_ticks_since_pause;
                                        m_ticks_since_pause = 0;
                                    }
                                }

        //Gets the timer's time
        Uint32                  GetTicksSinceStart()
                                {
                                    if(m_is_started == true)
                                    {
                                        if(m_is_paused == true) { return m_ticks_since_pause; }
                                        else                    { return SDL_GetTicks() - m_start_ticks; }
                                    }
                                    return 0;
                                }

        Uint32                  GetTicksDelta()
                                {
                                    if(m_is_started == true)
                                    {
                                        if(m_is_paused == true) { return m_ticks_since_pause; }
                                        else
                                        {
                                            Uint32 delta;

                                            m_start_ticks = SDL_GetTicks();
                                            delta = m_start_ticks - old_ticks_;
                                            old_ticks_ = m_start_ticks;
                                            return delta;
                                        }
                                    }
                                    return 0;
                                }

        //Checks the status of the timer
        bool                    IsStarted() { return m_started; }
        bool                    IsPaused()  { return m_paused; }

    private:
        //The clock time when the timer started
        Uint32                  m_ticks_since_start;
        Uint32                  m_old_ticks;

        //The ticks stored when the timer was paused
        Uint32                  m_ticks_since_pause;

        //The timer status
        bool                    m_is_paused;
        bool                    m_is_started;


};

}

#endif // CTIMER_H
