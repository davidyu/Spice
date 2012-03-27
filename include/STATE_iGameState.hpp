#ifndef IGAMESTATE_H
#define IGAMESTATE_H

namespace CORE
{
    class cGame;
}

namespace STATE
{

class iGameState
{
    public:
        // Should return new (derived type)
        // Used for registering class with Object Factory
        static  iGameState* CreateInstance() { return 0; }

        // Returns a pointer to a dynamically allocated clone
        virtual iGameState* Clone() = 0;

        virtual bool        OnEnter() = 0;
        virtual bool        OnExit() = 0;
        virtual void        Pause() = 0;
        virtual void        Resume() = 0;
        virtual void        Update(CORE::cGame* game, float delta) = 0;
        virtual void        Render(float percent_tick) = 0;


}; // class iGameState

} // namespace STATE

#endif // IGAMESTATE_H
