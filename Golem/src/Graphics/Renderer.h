/*
 * Renderer.h
 *
 *  Created on: 11-Dec-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_RENDERER_H_
#define GRAPHICS_RENDERER_H_

#include <memory>

#include "Camera/Camera.h"

namespace Golem {

class Renderer {
public:
    Renderer();
    ~Renderer();

    static Renderer* m_Instance;

    void Render();

    inline std::shared_ptr<Camera> GetCurrentCamera(){ return m_CurrentCamera;}

    std::shared_ptr<Camera> m_CurrentCamera;
};

} /* namespace Golem */

#endif /* GRAPHICS_RENDERER_H_ */
