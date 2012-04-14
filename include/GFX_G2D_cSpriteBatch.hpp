#ifndef CSPRITEBATCH_H
#define CSPRITEBATCH_H

namespace GFX
{
    class cTexture;

    namespace G2D
    {
        class cSpriteBatch
        {
        public:
            cSpriteBatch();
            virtual ~cSpriteBatch();

        private:
            cTexture* m_last_texture;
            float*      m_verticies;

            bool        m_blending_enabled;

        };
    }
}



#endif // CSPRITEBATCH_H
