// Based loosely on same class of libgdx

#ifndef CSPRITEBATCH_H
#define CSPRITEBATCH_H

namespace GFX
{
    // Forward Declarations
//    class cTexture;
//    class cTextureRegion;
    class cTextureMesh;
    class cTextureWrapper;
    typedef unsigned int GLuint;

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

            void DrawTexture(cTextureWrapper& tex, float x, float y, float w, float h);
            //void DrawTextureRegion(const cTextureWrapper& tex, float x, float y, int src_w, int src_h, float degrees, float scale);
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
            void            ChangeTexture(const cTextureWrapper& tex);
            void            RenderMesh();

            cTextureMesh*   m_mesh;
            cTextureWrapper* m_last_texture;

            bool            m_is_drawing;           // Set to true when Begin() is called, and false when End() is.
            bool            m_is_blending_enabled;
            int             mn_verticies;
            int             m_index;

        };
    }
}



#endif // CSPRITEBATCH_H
