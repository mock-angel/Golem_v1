/*
 * Renderer.cpp
 *
 *  Created on: 11-Dec-2020
 *      Author: anantha
 */

#include "Renderer.h"

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
#include "Camera/CameraManager.h"

namespace Golem {
Batch* batch = nullptr;

Renderer* Renderer::m_Instance = nullptr;

Renderer::Renderer() {
    // TODO Auto-generated constructor stub
    m_Instance = this;
}

Renderer::~Renderer() {
    // TODO Auto-generated destructor stub
}

void Renderer::Render(){
    //Get all active cameras;
    //render all scenes to each camera.


    //const auto& gameCameras = CameraManager::getInstance()->GetEditorCameras();

    //Step 0: Clear main screen.
    const auto& editorCameras = CameraManager::getInstance()->GetEditorCameras();



    if(batch == nullptr) batch = new Batch();

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    Camera::currentCamera = m_CurrentCamera = Game::getCamera();
    //{batch->Render();}

    for(auto& camera: editorCameras){
        Camera::currentCamera = m_CurrentCamera = camera;

        camera->use();
        if(m_CurrentCamera->getScreenClearType() == SCREEN_CLEAR_SOLIDCOLOR){
            glViewport(0, 0, camera->getWidth(), camera->getHeight());
            glClearColor(.3, .1, .2, 1.0);
            glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        }

        if(batch) batch->Render();
    }

    //m_CurrentCamera = Game::getCamera();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    //m_CurrentCamera = Game::getCamera();

}

} /* namespace Golem */
