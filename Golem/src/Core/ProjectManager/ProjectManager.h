/*
 * ProjectManager.h
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_PROJECTMANAGER_PROJECTMANAGER_H_
#define CORE_PROJECTMANAGER_PROJECTMANAGER_H_

#include <string>
#include <list>

#include "yaml-cpp/yaml.h"

namespace Golem {

class ProjectData{
public:
    ProjectData(const std::string& t_name, const std::string& t_dir){
        name = t_name;
        dir = t_dir;
    }
    ProjectData(){}
    std::string name;
    std::string dir;
};

class ProjectManager {

    static ProjectManager* Instance;

    std::list<ProjectData> m_projectList;
    std::string errorString;

    std::string projectListPath = "projects.list";
    YAML::Node projectList;

    //std::vector<YAML::Node> otherSubsidiary;
    ProjectData openedProject;
    bool m_projectOpened = false;
public:
    ProjectManager();
    virtual ~ProjectManager();

    void reloadList();
    bool addProject(const std::string& name, const std::string& dir);
    bool createProject(const ProjectData& projData);
    void openProject(const ProjectData& projData);

    bool isProjectOpened(){
        return m_projectOpened;
    }
    void updateInFile();
    const std::list<ProjectData>& getProjectList();

    inline ProjectData getProjectData(){
        return openedProject;
    }

    static ProjectManager* getInstance();
    const std::string& getError(){
        return errorString;
    }
};



} /* namespace Golem */

#endif /* CORE_PROJECTMANAGER_PROJECTMANAGER_H_ */
