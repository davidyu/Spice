/**
 * cImage class taken from The OpenGL Obj Loader
 */
#ifndef DCIMAGE_H
#define DCIMAGE_H

#include <string>
#include <gl/gl.h>
#include <SDL2/SDL.h>
#include <cassert>
using std::string;
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

        inline void CheckImage() const { assert(mp_surface != 0); }
    private:
        cImage(const cImage& rhs);            // Don't implement
        cImage& operator=(const cImage& rhs); // Don't implement

        SDL_Surface* mp_surface;
};

#endif // DCIMAGE_H
