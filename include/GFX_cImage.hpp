/**
 * cImage class taken from The OpenGL Obj Loader
 */
#ifndef GFX_CIMAGE_H
#define GFX_CIMAGE_H

#include <string>
#include <gl/gl.h>
#include <SDL2/SDL.h>
#include <cassert>
using std::string;

namespace GFX
{

    class cImage
    {
        public:
            cImage(const string& str_filepath);
            virtual ~cImage() { if (mp_surface) { SDL_FreeSurface(mp_surface); mp_surface = 0; } }

            bool IsTransparent() const;
            void ConvertPixelFormat();
            const GLint GetWidth() const    { CheckImage(); return mp_surface->w; }
            const GLint GetHeight() const   { CheckImage(); return mp_surface->h; }
            const void* GetPixels() const   { CheckImage(); return mp_surface->pixels; }

            inline void CheckImage() const;
        private:
            cImage(const cImage& rhs);            // Don't implement
            cImage& operator=(const cImage& rhs); // Don't implement

            SDL_Surface* mp_surface;
    }; // End class cImage

    void cImage::CheckImage() const  { assert(mp_surface != 0); }

} // End namespace GFX
#endif // GFX_CIMAGE_H
