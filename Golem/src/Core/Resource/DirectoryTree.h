/*
 * DirectoryTree.h
 *
 *  Created on: 24-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_RESOURCE_DIRECTORYTREE_H_
#define CORE_RESOURCE_DIRECTORYTREE_H_

#include<list>
#include<string>
#include<filesystem>


namespace Golem {

class DirectoryTree {
public:
    DirectoryTree(const std::filesystem::path& t_path);
    DirectoryTree() = default;
    ~DirectoryTree();

    void setPath(const std::filesystem::path& t_path);
    void setPath(const std::string& t_pathString);
    std::filesystem::path getPath(){
        return m_path;
    }
    void scan();
    std::list<DirectoryTree>& getDirectories();
    std::list<std::filesystem::path>& getFiles();
    operator std::basic_string<char>() const { return m_path; }
private:

    std::filesystem::path m_path;

    std::list<DirectoryTree> m_directories;
    std::list<std::filesystem::path> m_files;


};

} /* namespace Golem */

#endif /* CORE_RESOURCE_DIRECTORYTREE_H_ */
