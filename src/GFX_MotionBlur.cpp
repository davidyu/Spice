/**
 *
 */
#include "GFX_MotionBlur.hpp"
#include "GFX_cTextureWrapper.hpp"

namespace GFX
{
    bool CreateMotionBlurTexture(int quality, int interpolation, cTextureWrapper& tex)
    {	// Creates the motion blur texture
        int filter;

        switch(quality) {
            case 0:
                tex.SetTextureWidth(512);
                tex.SetTextureHeight(512);

//                tex.channels = 3;
//                tex.format = GL_RGB;
                break;
            case 1:
                tex.SetTextureWidth(256);
                tex.SetTextureHeight(256);

//                tex.channels = 3;
//                tex.format = GL_RGB;
                break;
            case 2:
                tex.SetTextureWidth(128);
                tex.SetTextureHeight(128);

//                tex.channels = 3;
//                tex.format = GL_RGB;
                break;
        }

        switch(interpolation) {
            case 0 :
                filter = GL_LINEAR;
                break;
            case 1:
                filter = GL_NEAREST;
                break;
        }
        GLuint texID = 0;

        GenerateTexture(texID,
        tex.GetTextureWidth(),
        tex.GetTextureHeight(),
        3,
        GL_RGB,
        filter, filter);

        tex.SetTextureID(texID);

        return true;
    }

//void RenderToMotionBlurTexture(bool FirstRenderTexture, int SceneFunc())
//{
//
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
//	glLoadIdentity();
//
//	glViewport(0, 0, motionBlur_Texture_X, motionBlur_Texture_Y);
//
//	// do we render first the scene or not?
//	if(FirstRenderTexture)
//		SceneFunc();
//
//	// render the old texture
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//
//		glDisable(GL_DEPTH_TEST);
//		glEnable(GL_BLEND);
//		glBlendFunc(GL_SRC_ALPHA,
//			GL_ONE_MINUS_SRC_ALPHA);
//			// For experimentation you can use these values too ;)
//			//GL_DST_ALPHA);
//			//GL_ONE_MINUS_SRC_COLOR );
//
//		// Set the textures customizable color
//		glColor4f(motionBlur_Red_intensity,
//				  motionBlur_Green_intensity,
//				  motionBlur_Blue_intensity,
//				  motionBlur_Alpha_intensity);
//
//		glMatrixMode(GL_PROJECTION);
//		glPushMatrix();
//
//			// put the texture on the screen
//			glBindTexture(GL_TEXTURE_2D, motionBlur_Texture);
//
//			// go to orthogonal view
//			glLoadIdentity();
//			glOrtho( 0, motionBlur_Texture_X, motionBlur_Texture_Y, 0, 0, 1);
//			glMatrixMode(GL_MODELVIEW);
//			glLoadIdentity();
//
//			glBegin(GL_QUADS);
//
//				glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
//				glTexCoord2f(0.0, 0.0);  glVertex2f(0, (GLfloat)motionBlur_Texture_Y);
//				glTexCoord2f(1.0, 0.0);  glVertex2f((GLfloat)motionBlur_Texture_X, (GLfloat)motionBlur_Texture_Y);
//				glTexCoord2f(1.0, 1.0);  glVertex2f((GLfloat)motionBlur_Texture_X, 0);
//
//			glEnd();
//
//			glMatrixMode(GL_PROJECTION);
//		glPopMatrix();
//		glMatrixMode(GL_MODELVIEW);
//
//		glEnable(GL_DEPTH_TEST);
//		glDisable(GL_BLEND);
//
//	glPopMatrix();
//
//	// do we put first the scene or not?
//	if(!FirstRenderTexture)
//		SceneFunc();
//
//
//	// copy the whole viewport to the teture
//	glBindTexture(GL_TEXTURE_2D, motionBlur_Texture);
//	glCopyTexImage2D(GL_TEXTURE_2D, 0, motionBlur_Texture_type, 0, 0,
//		motionBlur_Texture_X, motionBlur_Texture_Y, 0);
//
//	glViewport(0, 0, windowX, windowY);
//
//	// clear the viewport
//	glClearColor(0.0,0.0,0.0,0.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
//	glLoadIdentity();
//}

} // End namespace GFX
