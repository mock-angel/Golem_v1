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
#include "Debug.h"

namespace Golem {


WindowRenderer::~WindowRenderer(){

}

void WindowRenderer::render_sequence(){
#if 0
    if(batch == nullptr) batch = new Batch();
    if(frame == nullptr) {
        frame = new FrameBuffer();
        frame->create(720, 720);
    }
#endif
    //glClearColor(.3, .1, .2, 1.0);
    //glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    //frame->bind();

    //glClearColor(.3, .1, .2, 1.0);
    //glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    //std::cout<<m_width;

    //getNodeHandler()->RenderNodes();
    setGLViewport();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    {
        glClearColor(.3, .1, .2, 1.0);
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        static int prevWidth, prevHeight;


        std::shared_ptr<Camera> gameCam = Game::getCamera();
        if(prevWidth != m_width || prevHeight != m_height ){
            gameCam->setWidth(m_width);
            gameCam->setHeight(m_height);
            //gameCam->resizeTextures();

            prevWidth = m_width;
            prevHeight = m_height;
        }
        //Debug::log("width ", std::to_string(m_width));
        //Debug::log("height ", std::to_string(m_height));

        getGame()->render();

        //Game::getGame().lock()->render();
    }

    // Main renderer.
    getRenderer()->Render();

    render();
}

void WindowRenderer::setGLViewport(){
    glViewport(0, 0, m_width, m_height);
}

} /* namespace Golem */
