#ifndef DEMO_CPLAYSTATE_H
#define DEMO_CPLAYSTATE_H


class demo_cPlayState
{
    public:
        demo_cPlayState() {}
        virtual ~demo_cPlayState() {}

        bool OnEnter() {};
        bool OnExit() {};

        void Update(iApplication* game, float delta) {};
        void Render(float percent_tick) {};

        void HandleInput() {}
    private:
};

#endif // DEMO_CPLAYSTATE_H
