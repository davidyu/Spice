#include "CORE_cGame.hpp"

#include "STATE_iGameState.hpp"
#include "demo_cPlayState.hpp"


/*temp*/ #include <iostream>
         #include <cassert>
        using namespace std;

using namespace CORE;
using namespace STATE;

cGame::cGame() :
    m_sdl_state(0)
{
}

cGame::~cGame()
{
    //dtor
}

bool cGame::Initialise()
{
    SDL_Init( SDL_INIT_EVERYTHING );

    // Setup SDL Window and Render
    m_sdl_state = new cSDLState();
    m_sdl_state->window = SDL_CreateWindow(m_sdl_state->window_title,
        m_sdl_state->window_x,
        m_sdl_state->window_y,
        m_sdl_state->window_w , m_sdl_state->window_h,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    // Fullscreen?
    SDL_SetWindowFullscreen(m_sdl_state->window, m_sdl_state->is_fullscreen);
    // Renderer
    m_sdl_state->renderer = SDL_CreateRenderer(m_sdl_state->window,
                                    0, m_sdl_state->render_flags);
    // GL Context
    m_sdl_state->glctx = SDL_GL_CreateContext(m_sdl_state->window);
    SDL_GL_SetSwapInterval(1);

    m_input.Initialise();

    state_factory.RegisterClass("game", cPlayState::CreateInstance);
    m_state_manager.PushState(state_factory.CreateObject("game"));

}

bool cGame::Terminate()
{
    if (m_sdl_state) {

        if (m_sdl_state->renderer) {
            SDL_DestroyRenderer(m_sdl_state->renderer);
            SDL_free(m_sdl_state->renderer);
        }
        if (m_sdl_state->glctx)    {
            SDL_GL_DeleteContext(m_sdl_state->glctx);
            SDL_free(m_sdl_state->glctx);
        }
        if (m_sdl_state->window)   {
            SDL_DestroyWindow(m_sdl_state->window);
            SDL_free(m_sdl_state->window);
        }
        SDL_free(m_sdl_state);
    }

    SDL_Quit();
}

void cGame::MainLoop()
{
    iGameState* state;
    float delta, percent_tick; // Dummy vars for now; substitute timer values in later

    while (m_running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                EndGame();
            }
        }
        // Update Input-- set old keystates and current ones
        m_input.Update();

        // Game Loop
        state = m_state_manager.GetCurrent();
        /*DEBUG*/assert(state!=0);
        state->Update(this, delta);
        state->Render(this, percent_tick);
        SDL_RenderPresent(m_sdl_state->renderer);
    }
}

void cGame::EndGame()
{
    m_running = false;
}

CORE::Input& cGame::GetInput()
{
    return m_input;
}
cGameStateManager& cGame::GetStateManager()
{
    return m_state_manager;
}


