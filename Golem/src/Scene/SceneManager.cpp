/*
 * SceneManager.cpp
 *
 *  Created on: 19-Nov-2020
 *      Author: anantha
 */

#include "SceneManager.h"

#include "Core/Resource/ResourceManager.h"
#include "SceneLoader.h"

namespace Golem {

SceneManager* SceneManager::m_Instance = nullptr;

SceneManager::SceneManager() {
    // TODO Auto-generated constructor stub
    m_Instance = this;
}

SceneManager::~SceneManager() {
    // TODO Auto-generated destructor stub
    if(m_Instance == this)
        m_Instance = nullptr;
}

void SceneManager::Load(const std::string& t_scene){

    //TODO:: Work out ResourceManager's role in Scene loading.
    //std::shared_ptr<Scene> scene = ResourceManager::getInstance()->getResource<Scene>(t_scene);
    if(m_Instance){
        SceneLoader sceneLoader;
        m_Instance->m_currentScene = sceneLoader.loadScene(t_scene);
    }

}

std::shared_ptr<Node> SceneManager::GetCurrentScene(){
    return m_Instance->m_currentScene;
}

} /* namespace Golem */
