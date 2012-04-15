/**
 * Texture class taken from The OpenGL Object Loader project
 */

#ifndef CTEXTURE_H
#define CTEXTURE_H

#include <memory>
#include <cassert>
#include <string>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL.h>

using std::string;


namespace GFX
{
    // Forward declarations
    class cImage;

    class cTexture
    {
    public:
        cTexture(const string& str_filepath);
        // Require texture dimension to be power of two for < OGL 2.0 versions
        virtual ~cTexture();

        const bool	operator==(const cTexture& rhs) const;

        const GLuint	GetID() const;
        const bool	IsTransparent() const    { return m_is_transparent; }
        const bool	IsRegistered() const     { return mp_image.get() == 0; }
        void	    RegisterGL();
        void        BindGL() const;

        inline void	CheckTexture() const;
            //  REQUIRE: (pImage is not NULL) OR (the texture has been passed to OpenGL)

        static const GLuint	INVALID_ID;
    private:
        GLuint m_texture_id;
        bool m_is_transparent;
        std::shared_ptr<cImage> mp_image;
    }; // End class cTexture

    inline void cTexture::CheckTexture() const
    {
        assert(mp_image.get() != 0 || m_texture_id != INVALID_ID);
    }
    inline GLuint GetID() const
    {
        return m_texture_id;
    }
    inline void BindGL() const
    {
        glBindTexture (GL_TEXTURE_2D, m_texture_id);
    }

} // End namespace GFX

#endif // CTEXTURE_H
