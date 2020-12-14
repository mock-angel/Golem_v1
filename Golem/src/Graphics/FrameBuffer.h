/*
 * FrameBuffer.h
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_FRAMEBUFFER_H_
#define GRAPHICS_FRAMEBUFFER_H_

namespace Golem {

class FrameBuffer {
public:
    FrameBuffer();
    ~FrameBuffer();

    void create(int width, int height);
    void resize(int width, int height);
    void bind();
    void unbind();
    void del();
    unsigned int getTexture(){return m_TextureObject;}//Temp
private:
    unsigned int m_FBO;
    unsigned int m_TextureObject;
    unsigned int m_RBO;
};

} /* namespace Golem */

#endif /* GRAPHICS_FRAMEBUFFER_H_ */
