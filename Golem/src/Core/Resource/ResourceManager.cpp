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

ResourceRef ResourceManager::getResource(const std::string& resPath){

    load(resPath);
    if(m_resources.find(resPath) != m_resources.end()){

        const std::shared_ptr<Resource>& resource = m_resources[resPath];
        resource->load();
        return resource;
    }
    return nullptr;
}

void ResourceManager::load(const std::string& t_path){
    std::string localPath  = convertPathToLocal(t_path);
    //FileUtils::loadFile();
    std::filesystem::path p = t_path;

    //TODO: Pass extension to functon and determine file type.
    if(m_resources.find(t_path) == m_resources.end()){
        if(p.extension() == ".shader")
            m_resources[t_path] = std::make_shared<ShaderResource>(t_path);
        if(p.extension() == ".png")
            ;
    }
}

} /* namespace Golem */
