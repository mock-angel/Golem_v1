/*
 * Camera.cpp
 *
 *  Created on: 18-Oct-2020
 *      Author: anantha
 */

#include "Camera.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL_opengl.h>

#include "GLM.h"

#include "Debug.h"

namespace Golem {

Texture Camera::currentTexture;
std::shared_ptr<Camera> Camera::currentCamera;

Camera::Camera() {
    // TODO Auto-generated constructor stub
    //frameBuffer.
    // TODO init must not be called inside constructor.
    _init();
}

void Camera::_init(){

    //initialize texture
    frameBuffer.create(width, height);

    targetTexture.setTexture(frameBuffer.getTexture());//TODOC


}

//TODO: Change to bind?
void Camera::use(){

    //initialize texture
    frameBuffer.bind();
}

Camera::~Camera() {
    // TODO Auto-generated destructor stub
}

glm::mat4 Camera::getClipMatrix(){

    calculateProjection();

    return getProjMatrix()*getViewMatrix();
}

const glm::mat4& Camera::getViewMatrix(){
    view = glm::mat4(1.0f);
    //cameraPos = glm::vec3(0.5, 0, -3);
    view = glm::translate(view, cameraPos);

    return view;
}

void Camera::calculateProjection(){
    //TODO: Reinstate this statement.
    if(!projectionChangedFlag) return;

    if(perspective)
        proj = glm::perspective(glm::radians(fovy), width / height, nearPlane, farPlane);
    projectionChangedFlag = false;
}

void Camera::resizeTextures(){

    frameBuffer.resize(width, height);

    Texture createdTex;
    createdTex.setTexture(frameBuffer.getTexture());
    targetTexture = createdTex;
}

} /* namespace Golem */
