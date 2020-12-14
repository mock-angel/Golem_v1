/*
 * EditorCameraScript.h
 *
 *  Created on: 14-Dec-2020
 *      Author: anantha
 */

#ifndef EDITOR_EDITORCAMERASCRIPT_H_
#define EDITOR_EDITORCAMERASCRIPT_H_

#include "../ComponentOld.h"
#include "../Components/ComponentOldTypeHolder.h"

namespace Golem {

class Camera;

class EditorCameraScript : public ComponentOld {
    GAME_SCRIPT(EditorCameraScript);
public:
    //EditorCameraScript();
    ~EditorCameraScript();

    virtual void Start() override;
    virtual void update() override;

   inline std::shared_ptr<Camera> getCamera(){ return m_camera; }

private:
    std::shared_ptr<Camera> m_camera;
    float screenMousePosX, screenMousePosY;
    bool isCameraRotating = false;
    bool isCameraPanning = false;

    float m_ScrollSpeed = 1;
    float m_PanSpeed = 1;
};

} /* namespace Golem */

#endif /* EDITOR_EDITORCAMERASCRIPT_H_ */
