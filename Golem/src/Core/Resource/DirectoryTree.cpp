/*
 * DirectoryTree.cpp
 *
 *  Created on: 24-Nov-2020
 *      Author: anantha
 */

#include "DirectoryTree.h"

namespace Golem {

DirectoryTree::DirectoryTree(const std::filesystem::path& t_path) {
    // TODO Auto-generated constructor stub
    m_path = t_path;
}

DirectoryTree::~DirectoryTree() {
    // TODO Auto-generated destructor stub
}

std::list<DirectoryTree>& DirectoryTree::getDirectories(){
    return m_directories;
}

std::list<DirectoryFile>& DirectoryTree::getFiles(){
    return m_files;
}

void DirectoryTree::setPath(const std::filesystem::path& t_path){
    m_path = t_path;
}
void DirectoryTree::setPath(const std::string& t_pathString){
    m_path = t_pathString;
}

void DirectoryTree::scan(){
    m_directories.clear();
    m_files.clear();

    for (const auto & entry : std::filesystem::directory_iterator(m_path)){
        const std::filesystem::path& path = entry.path();
        if(std::filesystem::is_directory(path))
            m_directories.push_back(DirectoryTree(path));
        else
            m_files.push_back(DirectoryFile(path));
    }

    for(auto & directoryTree : m_directories)
        directoryTree.scan();
}

} /* namespace Golem */
