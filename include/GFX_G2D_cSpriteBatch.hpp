// Based loosely on same class of libgdx

#ifndef CSPRITEBATCH_H
#define CSPRITEBATCH_H

#include "GFX_Color4.hpp"

namespace GFX
{
    // Forward Declarations
    class cTextureMesh;
    class cTextureWrapper;

    namespace G2D
    {
        class cSpriteBatch
        {
        public:
            cSpriteBatch();
            cSpriteBatch(int n_batch); // Number of draws per batch
            virtual ~cSpriteBatch();

            void Destroy();

            void Begin();
            void End();

            void DrawTexture(const cTextureWrapper& tex, float x, float y, float w, float h);
            void DrawTexturePos2Dim2Origin2Scale2Rot(const cTextureWrapper& tex, float x, float y, float w, float h
                                   , float x_origin, float y_origin
                                   , float x_scale, float y_scale, float rot_degrees);
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
            void SetColor(const Color4 col);

        private:
            // Private methods
            void            ChangeTexture(const cTextureWrapper& tex);
            void            FlushIfNewTextureOrBatchFull(const cTextureWrapper& tex); // Best function name ever...
            void            Initialise(int n_batch);
            void            RenderMesh();


            cTextureMesh*   m_mesh;
            const cTextureWrapper* m_last_texture;
            float            m_reciprocal_tex_width, m_reciprocal_tex_height;

            Color4          m_current_color;

            bool            m_is_drawing;           // Set to true when Begin() is called, and false when End() is.
            bool            m_is_blending_enabled;
            int             mn_max_batch;           // Number of draws per batch
            int             m_index;

        };
    }
}



#endif // CSPRITEBATCH_H
