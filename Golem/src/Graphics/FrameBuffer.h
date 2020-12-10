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
    void bind();
    void unbind();
private:
    unsigned int m_frameBuffer;
};

} /* namespace Golem */

#endif /* GRAPHICS_FRAMEBUFFER_H_ */
