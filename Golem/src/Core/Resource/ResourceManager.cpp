/*
 * ResourceManager.cpp
 *
 *  Created on: 20-Nov-2020
 *      Author: anantha
 */

#include "ResourceManager.h"
#include "yaml-cpp/yaml.h"

namespace Golem {

ResourceManager *ResourceManager::m_Instance = nullptr;

ResourceManager::ResourceManager() {
    // TODO Auto-generated constructor stub
    m_Instance = this;
}

ResourceManager::~ResourceManager() {
    // TODO Auto-generated destructor stub
}

void ResourceManager::refresh(){
    //m_projectData.dir;
}

void ResourceManager::setProject(ProjectData& projData){
    //m_projectData = projData;
    m_dirTree.setPath(projData.dir);
    m_dirTree.scan();
}

std::list<std::string> ResourceManager::getFoldersInPath(std::string _path){
    std::list<std::string> _retStr;
    for (const auto & entry : std::filesystem::directory_iterator(_path)){

        if(entry.path().extension() == "")
            _retStr.push_back(entry.path());
    }
    return _retStr;
}

std::list<std::string> ResourceManager::getFilesInPath(std::string _path){
    std::list<std::string> _retStr;
    for (const auto & entry : std::filesystem::directory_iterator(_path)){

        if(entry.path().extension() != "")
            _retStr.push_back(entry.path());
    }
    return _retStr;
}

} /* namespace Golem */
