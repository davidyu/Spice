#ifndef IGAMESTATE_H
#define IGAMESTATE_H

class iApplication;

class iGameState
{
    public:
        // Should return new (derived type)
        // Used for registering class with Object Factory
        iGameState* CreateInstance() = 0;

        virtual bool OnEnter() = 0;
        virtual bool OnExit() = 0;
        virtual void Update(iApplication* game, float delta) = 0;
        virtual void Render(float percent_tick) = 0;
};

#endif // IGAMESTATE_H
