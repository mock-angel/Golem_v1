/*
 * SceneManager.h
 *
 *  Created on: 19-Nov-2020
 *      Author: anantha
 */

#ifndef SCENE_SCENEMANAGER_H_
#define SCENE_SCENEMANAGER_H_

#include "Scene.h"

namespace Golem {

class SceneManager {
public:

    static SceneManager* m_Instance;
    static SceneManager* getInstance(){
        return m_Instance;
    }

    std::shared_ptr<Scene> m_currentScene = nullptr;

    SceneManager();
    ~SceneManager();
};

} /* namespace Golem */

#endif /* SCENE_SCENEMANAGER_H_ */
