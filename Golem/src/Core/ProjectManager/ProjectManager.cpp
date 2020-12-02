/*
 * ProjectManager.cpp
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#include "ProjectManager.h"

#include <iostream>

#include <fstream>
#include <map>
#include <string>
#include <filesystem>

#include "yaml-cpp/yaml.h"
#include "Debug.h"
#include "../Resource/ResourceManager.h"
#include "Scene/SceneLoader.h"

namespace Golem {

ProjectManager* ProjectManager::Instance = nullptr;

ProjectManager::ProjectManager() {
    Instance = this;
    reloadList();
}

ProjectManager::~ProjectManager() {
    // TODO Auto-generated destructor stub
}

void ProjectManager::reloadList(){
    std::ifstream fin(projectListPath);
    std::string fullstr, linestr;

    while ( getline (fin, linestr) )
        fullstr += linestr+'\n';

    fin.close();

    projectList = YAML::LoadFile(projectListPath);

    //otherSubsidiary = YAML::LoadAllFromFile("projects2.list");

    m_projectList.clear();

    for(auto yamlIt : projectList){
        std::string name = yamlIt.first.as<std::string>();
        std::string dir = yamlIt.second.as<std::string>();

        m_projectList.emplace_back(name, dir);
    }
}

bool ProjectManager::addProject(const std::string& name, const std::string& dir){
    m_projectList.emplace_back(name, dir);

    updateInFile();
    return true;
}

bool ProjectManager::createProject(const ProjectData& projData){

    //Create Directory Res, Res/Scripts, Res/Sprites,
    //Res/Images, Res/Shaders, Res/Textures
    std::filesystem::create_directory(projData.dir + "/Res");
    std::filesystem::create_directory(projData.dir + "/Res/Scripts");
    std::filesystem::create_directory(projData.dir + "/Res/Sprites");
    std::filesystem::create_directory(projData.dir + "/Res/Textures");
    std::filesystem::create_directory(projData.dir + "/ProjectSettings");

    YAML::Node dirData;
    dirData["res_dir"] = "Res";
    dirData["scripts_dir"] = "Res/Scripts";
    dirData["sprites_dir"] = "Res/Sprites";
    dirData["textures_dir"] = "Res/Textures";
    dirData["projectsettings_dir"] = "ProjectSettings";

    std::string dirAssetDirectory = projData.dir + "/ProjectSettings/Directories.asset";

    std::ofstream fout(dirAssetDirectory);
    fout<<dirData;

    //Create c# project files.
    system(("cd " + projData.dir +" && dotnet new console --no-restore").c_str());

    m_projectList.emplace_back(projData.name, projData.dir);
    projectList[projData.name] = projData.dir;
    updateInFile();
    return true;
}

void ProjectManager::updateInFile(){
    std::ofstream fout(projectListPath);
    fout<<projectList;
}

const std::list<ProjectData>& ProjectManager::getProjectList(){
    return m_projectList;
}

void ProjectManager::openProject(const ProjectData& projData){
    openedProject = projData;
    m_projectOpened = true;
    ResourceManager::getInstance()->setProject(openedProject);
    SceneLoader sceneLoader;
    sceneLoader.loadScene("test.yaml");
}

ProjectManager* ProjectManager::getInstance(){
    return Instance;
}

} /* namespace Golem */
