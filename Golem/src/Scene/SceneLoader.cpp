/*
 * SceneLoader.cpp
 *
 *  Created on: 01-Dec-2020
 *      Author: anantha
 */

#include "SceneLoader.h"

#include <unordered_map>

#include "yaml-cpp/yaml.h"
#include "Components/ComponentTypeHolder.h"
#include "Node.h"
#include "Debug.h"

namespace Golem {

SceneLoader::SceneLoader() {
    // TODO Auto-generated constructor stub

}

SceneLoader::~SceneLoader() {
    // TODO Auto-generated destructor stub
}

std::shared_ptr<Node> SceneLoader::loadScene(const std::string& path){

    std::vector<YAML::Node> first = YAML::LoadAllFromFile(path);
    YAML::Node yamlNode = first[0];

    std::list<long> nodesFileId;
    std::list<long> componentsFileId;

    std::unordered_map<long, std::shared_ptr<Node>> nodesMap;
    std::unordered_map<long, std::shared_ptr<Component>> componentsMap;

    nodesFileId = yamlNode["m_NodesList"].as<std::list<long>>();
    componentsFileId = yamlNode["m_ComponentsList"].as<std::list<long>>();

    for(long compoYaml : componentsFileId){
        std::shared_ptr<Component> createdComponent;
        YAML::Node compoNode = yamlNode[compoYaml];

        std::string compoType = compoNode["m_ComponentType"].as<std::string>();
        //std::string compoType = compoNode["m_ComponentType"].as<std::string>();
        createdComponent = ComponentTypeHolder::getComponent(compoType);
        componentsMap[compoYaml] = createdComponent;
    }

    std::shared_ptr<Node> sceneNode = Node::Instantiate().lock();

    for(long nodeYaml : nodesFileId){
        std::shared_ptr<Node> createdNode;

        YAML::Node compoNode = yamlNode[nodeYaml];
        std::list<long> compos = compoNode["m_Components"].as<std::list<long>>();


        createdNode = Node::Instantiate().lock();
        nodesMap[nodeYaml] = createdNode;
        createdNode->SetName(yamlNode[nodeYaml]["m_Name"].as<std::string>());
        for(long compoNum: compos){
            std::weak_ptr<Component> componentToAdd = componentsMap[compoNum];
            createdNode->addComponent(componentToAdd);
        }

        sceneNode->AddChild(createdNode);
    }

    return sceneNode;
}

} /* namespace Golem */
