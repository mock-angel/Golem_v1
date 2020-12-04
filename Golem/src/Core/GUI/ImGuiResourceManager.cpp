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

void drawGuiDirTree(DirectoryTree& tree){

    //TODO:: ResourceManager must be informed of selected Resource.
    ResourceManager* resManager = ResourceManager::getInstance();
    //resManager->SetResourceSelected();

    //if(!substitute.length()) treeNodeOpened = ImGui::TreeNode(f.lexically_relative(parent).c_str());
    if(ImGui::TreeNode(tree.getPath().c_str())){
        std::list<DirectoryTree>& treeList = tree.getDirectories();
        for(DirectoryTree& tree_dir: treeList)
            drawGuiDirTree(tree_dir);

        //ImVec2 fullWidthSize = ImVec2(ImGui::GetContentRegionAvailWidth(), 0);
        std::list<DirectoryFile>& fileList = tree.getFiles();
        for(DirectoryFile& file: fileList){

            ImGui::Selectable(file.getPath().c_str(), &file.m_selected);
            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0))
            {
                Debug::log("Double Click on : ", file.getPath().c_str());
            }
        }
        ImGui::TreePop();
    }
}

void ImGuiResourceManager::update(){
    if(!isOpen()) return;

    ResourceManager* resManager = ResourceManager::getInstance();

    std::string resPathParent = resManager->getProjectPath();
    if(resPathParent.length() > 0){
        ImGui::Begin("ImGuiResourceManager", NULL, ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoScrollbar);

        drawGuiDirTree(resManager->getDirectoryTree());

        ImGui::End();
    }
}

} /* namespace Golem */
