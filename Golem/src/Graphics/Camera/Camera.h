/*
 * Camera.h
 *
 *  Created on: 18-Oct-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_CAMERA_CAMERA_H_
#define GRAPHICS_CAMERA_CAMERA_H_

#include <memory>

#include "Graphics/Textures/Texture.h"
#include "Graphics/FrameBuffer.h"

#include <glm/glm.hpp>

namespace Golem {

enum ScreenClearType{
    SCREEN_CLEAR_SOLIDCOLOR
};

class Camera {
public:
    Camera();
    virtual ~Camera();

    void _init();

    void calculateProjection();
    void calculateViewMatrix();

    inline void setPerspective(bool value){ perspective = value; }
    inline void setWidth(float t_width){ width = t_width; projectionChangedFlag = cameraSizeChangedFlag = true;}
    inline void setHeight(float t_height){ height = t_height; projectionChangedFlag = cameraSizeChangedFlag = true;}
    inline void setCameraSize(float t_width, float t_height){ if(width == t_width && height == t_height) return; width = t_width;  height = t_height; }
    inline void setFov(float t_fovy){ fovy = t_fovy; }
    inline void setNearPlane(float t_nearz){ nearPlane = t_nearz; }
    inline void setFarPlane(float t_farz){ farPlane = t_farz; }
    inline void setDepth(int t_depth){ depth = t_depth; }

    glm::mat4 getClipMatrix();
    const glm::mat4& getProjMatrix(){ return proj; }
    const glm::mat4& getModelMatrix();
    const glm::mat4& getViewMatrix();

    inline float getWidth(){ return width; }
    inline float getHeight(){ return height; }
    inline float getFov(){ return fovy; }
    inline float getNearPlane(){ return nearPlane; }
    inline float getFarPlane(){ return farPlane; }
    inline int getDepth(){ return depth; }
    inline ScreenClearType getScreenClearType(){ return screenClearType; }

    //(Internal) for rendering.
    static Texture getCurrentTexture(){ return currentTexture; }
    static std::shared_ptr<Camera> getCurrentCamera(){ return currentCamera; }

    Texture getTargetTexture(){ return targetTexture; }
    void resizeTextures();

    void use();

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, -3.0f);
private:

    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    //glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
    glm::vec4 clearColor;
    ScreenClearType screenClearType = SCREEN_CLEAR_SOLIDCOLOR;

    bool perspective = true;
    float width = 1920.0f;
    float height = 1080.0f;
    float fovy = 45.0f;
    float nearPlane = 0.1f;
    float farPlane = 100.0f;
    int depth = 0;

    bool projectionChangedFlag = true;
    bool cameraSizeChangedFlag = true;

    glm::mat4 proj = glm::mat4(1.0f);
    //glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);

    //(Internal) for rendering
    static Texture currentTexture;
    static std::shared_ptr<Camera> currentCamera;

    Texture targetTexture;
    FrameBuffer frameBuffer;

    friend class Renderer;
};

} /* namespace Golem */

#endif /* GRAPHICS_CAMERA_CAMERA_H_ */
