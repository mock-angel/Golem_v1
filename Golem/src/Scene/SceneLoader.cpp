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

void SceneLoader::loadScene(const std::string& path){
    Debug::log("Trace 0");
    std::vector<YAML::Node> first = YAML::LoadAllFromFile(path);

    YAML::Node yamlNode = first[0];
    Debug::log("Trace 0.1");
    std::list<long> nodesYaml;
    std::list<long> componentsYaml;
    Debug::log("Trace 0.2");
    std::unordered_map<long, std::shared_ptr<Node>> mpNodes;
    std::unordered_map<long, std::shared_ptr<Component>> mpComponents;
    std::shared_ptr<Component> t;
    std::shared_ptr<Node> n;
    Debug::log("Trace 1");
    nodesYaml = yamlNode["m_NodesList"].as<std::list<long>>();
    componentsYaml = yamlNode["m_ComponentsList"].as<std::list<long>>();
    Debug::log("Trace 2");
    for(long compoYaml : componentsYaml){

        YAML::Node compoNode = yamlNode[compoYaml];

        std::string compoType = compoNode["m_ComponentType"].as<std::string>();
        //std::string compoType = compoNode["m_ComponentType"].as<std::string>();
        t = ComponentTypeHolder::getComponent(compoType);
        mpComponents[compoYaml] = t;
    }
    Debug::log("Trace 3");
    for(long nodeYaml : nodesYaml){
        YAML::Node compoNode = yamlNode[nodeYaml];

        std::list<long> compos = compoNode["m_Components"].as<std::list<long>>();
        //std::string compoType = compoNode["m_ComponentType"].as<std::string>();
        n = Node::Instantiate().lock();
        mpNodes[nodeYaml] = n;

        for(auto& compoNum: compos){
            std::weak_ptr<Component> g = mpComponents[compoNum];
            n->addComponent(g);
        }
    }
    Debug::log("Trace 4");
}

} /* namespace Golem */
