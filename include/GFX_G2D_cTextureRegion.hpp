/**
 * Texture Region class adapted from libgdx
 */
#ifndef CTEXTUREREGION_H
#define CTEXTUREREGION_H

#include <vector> // TODO: DON'T USE?

class cTexture;

namespace GFX
{
    // Forward Declarations
    class cTexture;

    namespace G2D
    {
        class cTextureRegion
        {
        public:
            // Empty constructor
            cTextureRegion();

            // Creates texture region the whole size of the passed texture
            cTextureRegion(const cTexture& tex);

            // Creates texture region using offsets, height, and width of the passed texture
            // Negative dimensions indicate flips
            cTextureRegion(const cTexture&  tex, int x_offset, int y_offset, int width, int height);

            // Creates texture region using texture mapping coords
            cTextureRegion(const cTexture& tex, float u, float v, float u2, float v2);

            // Copy constructor
            cTextureRegion(const cTextureRegion& rhs);

            // Creates texture region using offsets, height, and width of the passed texture region
            // Negative dimensions indicate flips
            cTextureRegion(const cTextureRegion& tex_reg, int x_offset, int y_offset, int width, int height);

            virtual ~cTextureRegion();

            // Static functions
            static vector<cTextureRegion> SplitTextureHorizontal(const cTexture& tex, int frame_width, int y_offset);
            static vector<cTextureRegion> SplitTextureRegionHorizontal(const cTextureRegion& tex_reg, int frame_width, int y_offset);
            //TODO: ADD VERTICAL SPLITS??

            // Getters
            const cTexture& GetTexture() const;

            // Setters
            void SetRegionFromDimensions(int x_offset, int y_offset, int width, int height);
            void SetRegionFromTexture(const cTexture& tex);
            void SetRegionFromTextureRegion(const cTextureRegion& tex_reg, int x_offset, int y_offset, int width, int height);
            void SetRegionFromUV(float u, float v, float u2, float v2);

            void SetTexture(const cTexture& tex);

        protected:
            float m_u, m_v;     //!< Top, left
            float m_u2, m_v2;   //!< Bottom, right
            cTexture* mp_texture; //!< Pointer to the base texture. TODO: use shared_ptr ?
        };

    }
}

#endif // CTEXTUREREGION_H
