/*
 * ResourceManager.h
 *
 *  Created on: 20-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_RESOURCE_RESOURCEMANAGER_H_
#define CORE_RESOURCE_RESOURCEMANAGER_H_

#include <unordered_map>
#include <filesystem>

#include "GuidGenerator.h"
#include "../ProjectManager/ProjectManager.h"
#include "Debug.h"
#include "Resource.h"
#include "DirectoryTree.h"


namespace Golem {
/*
class FolderPath{
    std::shared_ptr<FolderPath> m_folders;
    std::shared_ptr<FilePath> m_files;

    std::string path;
    bool m_isFolder;
    bool m_isFolderEmpty()
};
*/
enum ResourceType{
    ResourceType_Scene,
    ResourceType_Image,
    ResourceType_Asset,
    ResourceType_Texture,
    ResourceType_Shader,
    ResourceType_Material,
    ResourceType_MonoScript,
    ResourceType_None,
};

class ProjectData;

class ResourceMeta{
public:

private:
    boost::uuids::uuid guid;
    ResourceType type;
};

class AssetData{
public:
private:
    std::string m_assetName;

};

class FileIndex{
public:
    const std::filesystem::path& getPath(){
        return m_path;
    }

    bool check(){
        if(std::filesystem::exists(m_path)){
            //check if modified
            return true;
        }
        else {
            return false;
        }
    }

private:
    std::filesystem::path m_path;

};

class FolderIndex{
private:
    std::list<std::shared_ptr<FolderIndex>> m_folders;
    std::list<std::shared_ptr<FileIndex>> m_files;
    std::filesystem::path m_path;
public:
    inline const std::list<std::shared_ptr<FolderIndex>>& getFolders(){
        return m_folders;
    }

    inline const std::list<std::shared_ptr<FileIndex>>& getFiles(){
        return m_files;
    }

    bool scan(){

        if(!std::filesystem::exists(m_path))
            return false;

        std::list<std::filesystem::path> folderPath;
        std::list<std::filesystem::path> filePath;
        for (const auto & entry : std::filesystem::directory_iterator(m_path)){
            if(std::filesystem::is_directory(entry.path()))
                folderPath.push_back(entry.path());
            if(std::filesystem::is_directory(entry.path()))
                filePath.push_back(entry.path());
        }

        for(const auto& folder :m_folders){
            folder->scan();
        }

        for(const auto& file :m_files){
            if(!file->check());
        }

        return true;

    }


};


class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();

    void reload();
    void refresh();

    static ResourceManager *m_Instance;
    static ResourceManager* getInstance(){
        return m_Instance;
    }

    void setProject(ProjectData& projData);
    inline std::string getProjectPath(){
        return ProjectManager::getInstance()->getProjectData().dir;
    }

    std::list<std::string> getFoldersInPath(std::string _path);
    std::list<std::string> getFilesInPath(std::string _path);

    ResourceRef getResource(const std::string& path){
        if(m_resources.find(path) == m_resources.end())
            //Loadresource now
            load(path);
        return m_resources[path];
    }

    inline DirectoryTree& getDirectoryTree(){
        return m_dirTree;
    }

    template<class T>
    std::shared_ptr<T> getResource(const std::string& resPath){

        if(m_resources.find(resPath) != m_resources.end()){

            const std::shared_ptr<Resource>& resource = m_resources[resPath];


            return resource;
        }

    }
private:
    GuidGenerator m_guidGen;
    //ProjectData m_projectData;

    std::unordered_map<std::string, std::shared_ptr<Resource>> m_resources;

    std::unordered_map<std::string, ResourceMeta> m_resourcesMeta;
    std::unordered_map<std::string, AssetData> m_assets;

    std::string resHostDir = "res:/";

    DirectoryTree m_dirTree;

    void load(const std::string& t_path){
        std::string localPath  = convertPathToLocal(t_path);
    }
    std::string convertPathToLocal(const std::filesystem::path& t_path){
        std::string relativePath = t_path.lexically_relative(resHostDir);

        //Path is relative to project.
        if(relativePath[0] == '.')
            return t_path;

        //Path is root directory
        else if(relativePath.length() == 0)
            return t_path;
        else return t_path / relativePath;
    }
    //Check and compare every resource with its filesystem meta and time resource was changed
    //If any change was detected, recompile is script,
    void onWindowFocused();
};

} /* namespace Golem */

#endif /* CORE_RESOURCE_RESOURCEMANAGER_H_ */
