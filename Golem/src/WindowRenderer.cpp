/*
 * WindowRenderer.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include "WindowRenderer.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL_opengl.h>
#include <memory>
#include <iostream>

#include "Game.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Graphics/BatchRenderer.h"
#include "Graphics/FrameBuffer.h"

namespace Golem {

Batch* batch = nullptr;
FrameBuffer* frame = nullptr;

WindowRenderer::~WindowRenderer(){

}

void WindowRenderer::render_sequence(){

    if(batch == nullptr) batch = new Batch();
    if(frame == nullptr) {
        frame = new FrameBuffer();
        frame->create(720, 720);
    }

    glClearColor(.3, .1, .2, 1.0);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    frame->bind();
    //glClearColor(0.2, 0.3, 0.3, 1.0);
    glClearColor(.3, .1, .2, 1.0);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    //std::cout<<m_width;

    //getNodeHandler()->RenderNodes();
    getGame()->render();

    batch->Render();

    render();

    frame->unbind();
}

void WindowRenderer::setGLViewport(){
    glViewport(0, 0, m_width, m_height);
}

} /* namespace Golem */
