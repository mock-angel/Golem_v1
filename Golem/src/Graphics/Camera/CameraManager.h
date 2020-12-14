/*
 * CameraManager.h
 *
 *  Created on: 11-Dec-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_CAMERA_CAMERAMANAGER_H_
#define GRAPHICS_CAMERA_CAMERAMANAGER_H_

#include <list>
#include <memory>

#include "Res/Scripts/CameraScript.h"
#include "Camera.h"
#include "Core/Layer/Layer.h"

namespace Golem {

class CameraManager : public Layer{
public:
    CameraManager();
    ~CameraManager();

    static CameraManager* m_Instance;
    static CameraManager* getInstance(){ return m_Instance; }


    inline const auto& GetEditorCameras(){ return m_EditorCameras;}
    inline const auto& GetGameCameras(){ return m_GameCameras;}

    inline void AddEditoramera(std::shared_ptr<Camera> t_camera){ m_EditorCameras.push_back(t_camera); }
    inline void AddGameCamera(std::shared_ptr<Camera> t_camera){ m_GameCameras.push_back(t_camera); }

    static std::shared_ptr<Camera> CreateEditorCamera(){ auto cam = std::make_shared<Camera>(); m_Instance->m_EditorCameras.push_back(cam); return cam; }
    std::list<std::shared_ptr<Camera>> m_Cameras;
    std::list<std::shared_ptr<Camera>> m_EditorCameras;
    std::list<std::shared_ptr<Camera>> m_GameCameras;
};

} /* namespace Golem */

#endif /* GRAPHICS_CAMERA_CAMERAMANAGER_H_ */
