// Based loosely on same class of libgdx

#ifndef CSPRITEBATCH_H
#define CSPRITEBATCH_H

namespace GFX
{
    class cTexture;
    class cTextureRegion;
    class cTextureMesh;

    namespace G2D
    {
        class cSpriteBatch
        {
        public:
            cSpriteBatch();
            virtual ~cSpriteBatch();

            void Destroy();

            void Begin();
            void End();

            void DrawTexture(const cTextureRegion& tex_reg, int x, int y, int w, int h);
            void DrawTextureRegion(const cTextureRegion& tex_reg, float x, float y, int src_w, int src_h, float degrees, float scale);
            // TODO -- Add more draws

            // Renders all pending textures to be drawn, without ending the sprite batch
            void Flush();

            // Getters
            bool IsBlendingEnabled();

            // Setters
            void SetBatchSize(int i);
            void SetBlendFunction(int src_func, int dest_func);
            void SetBlending(bool b); // Enable or disable blending. !Flushes batches first.

        private:
            // Private methods
            void            ChangeTexture(const cTexture& tex);
            void            RenderMesh();

            cTextureMesh*   m_mesh;
            cTexture*       m_last_texture;

            bool            m_is_blending_enabled;

        };
    }
}



#endif // CSPRITEBATCH_H
