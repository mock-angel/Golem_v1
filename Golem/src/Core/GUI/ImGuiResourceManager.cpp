/*
 * ImGuiResourceManager.cpp
 *
 *  Created on: 20-Nov-2020
 *      Author: anantha
 */

#include "ImGuiResourceManager.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"

#include "../Resource/ResourceManager.h"
#include "../Resource/DirectoryTree.h"


namespace Golem {

ImGuiResourceManager::ImGuiResourceManager() {
    // TODO Auto-generated constructor stub

}

ImGuiResourceManager::~ImGuiResourceManager() {
    // TODO Auto-generated destructor stub
}

void createTree(const std::string& parent, const std::string& directory, const std::string& substitute = ""){

    std::list<std::string> _folders = ResourceManager::getInstance()->getFoldersInPath(directory);
    std::list<std::string> _files = ResourceManager::getInstance()->getFilesInPath(directory);

    std::filesystem::path f = directory;

    //if(substitute);

    bool treeNodeOpened;

    if(!substitute.length()) treeNodeOpened = ImGui::TreeNode(f.lexically_relative(parent).c_str());
    else treeNodeOpened = ImGui::TreeNode(substitute.c_str());

    if(treeNodeOpened){

        for(const auto& folder: _folders)

            createTree(directory, folder);

        ImVec2 v2 = ImVec2(ImGui::GetContentRegionAvailWidth(), 0);
        for(const auto& file: _files){
            f = file;
            ImGui::Button(f.lexically_relative(parent).c_str(), v2);
        }
        ImGui::TreePop();
    }
}

void drawGuiDirTree(DirectoryTree& tree){
    bool treeNodeOpened = false;

    //if(!substitute.length()) treeNodeOpened = ImGui::TreeNode(f.lexically_relative(parent).c_str());
    treeNodeOpened = ImGui::TreeNode(tree.getPath().c_str());

    if(treeNodeOpened){
        auto& treeList = tree.getDirectories();
        for(auto& tree_dir: treeList) drawGuiDirTree(tree_dir);

        ImVec2 fullWidthSize = ImVec2(ImGui::GetContentRegionAvailWidth(), 0);
        auto& fileList = tree.getFiles();
        for(const auto& file: fileList){
            ImGui::Button(file.c_str(), fullWidthSize);
            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0))
            {
                // Do stuff on Selectable() double click.
                Debug::log("Double Click on : ", file.c_str());
            }
        }
        ImGui::TreePop();
    }
}

void ImGuiResourceManager::update(){
    if(!isOpen()) return;

    ResourceManager* resManager = ResourceManager::getInstance();

    std::string resPathParent = resManager->getProjectPath();
    if(!resPathParent.length()) return;

    ImGui::Begin("Resource Manager");
    //createTree(resPathParent, resPathParent, "Res::/");
    drawGuiDirTree(resManager->getDirectoryTree());
    ImGui::End();
}

} /* namespace Golem */
