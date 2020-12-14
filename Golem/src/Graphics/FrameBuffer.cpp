/*
 * FrameBuffer.cpp
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#include "FrameBuffer.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL_opengl.h>
#include <string>
#include "Textures/Texture.h"
#include "Debug.h"

namespace Golem {

FrameBuffer::FrameBuffer() {
    // TODO Auto-generated constructor stub

}

FrameBuffer::~FrameBuffer() {
    // TODO Auto-generated destructor stub
}

void FrameBuffer::create(int width, int height){

    Texture frameTexture;
    frameTexture.create(width, height);
    m_TextureObject = frameTexture.get();

    //glGenTextures(1, &m_frameBuffer);
    glGenFramebuffers(1, &m_FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

    GLuint depthrenderbuffer;
    glGenRenderbuffers(1, &depthrenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthrenderbuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer);

    m_RBO = depthrenderbuffer;

    // Set "renderedTexture" as our colour attachement #0
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, frameTexture.get(), 0);
    //glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, frameTexture.get(), 0);

    // Set the list of draw buffers.
    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers); // "1" is the size of DrawBuffers

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)//something went wrong
        Debug::log("FRAME_BUFFER_ERROR: Couldn't create FrameBuffer.");
}

void FrameBuffer::bind(){
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
}

void FrameBuffer::unbind(){
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

} /* namespace Golem */
