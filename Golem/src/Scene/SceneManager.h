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

    //TODO:: Make it possible to load scenes by passing in nodes.
    static void Load(const std::string& t_scene);

    static std::shared_ptr<Node> GetCurrentScene();

    std::shared_ptr<Node> m_currentScene = nullptr;

    SceneManager();
    ~SceneManager();
};

} /* namespace Golem */

#endif /* SCENE_SCENEMANAGER_H_ */
