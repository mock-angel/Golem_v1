/*
 * EditorCameraScript.cpp
 *
 *  Created on: 14-Dec-2020
 *      Author: anantha
 */

#include "EditorCameraScript.h"

#include "Core/Input/InputSystem.h"
#include "Core/Input/Input.h"
#include "Debug.h"
#include "Graphics/Camera/CameraManager.h"

namespace Golem {

EditorCameraScript::EditorCameraScript() {

    m_ScrollSpeed = 1;
    m_PanSpeed = 1;

}

EditorCameraScript::~EditorCameraScript() {
    // TODO Auto-generated destructor stub
}

void EditorCameraScript::update(){

    if(Input::GetMouseScrollY()){

        glm::vec3 v = m_camera->cameraPos;
        m_camera->cameraPos.z += Input::GetMouseScrollY() * m_ScrollSpeed;

        //Debug::log( "EditorCameraScript ScrollY recieved", std::to_string(v.z) );
        //this->getGameObject();

    }
}

void EditorCameraScript::Start(){
    m_camera = CameraManager::CreateEditorCamera();

}

} /* namespace Golem */
