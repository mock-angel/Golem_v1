/*
 * GuiHeirarchy.cpp
 *
 *  Created on: 03-Dec-2020
 *      Author: anantha
 */

#include "GuiNodeHeirarchy.h"

#include <memory>

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"
#include "Scene/SceneManager.h"

namespace Golem {

GuiNodeHeirarchy::GuiNodeHeirarchy() {
    // TODO Auto-generated constructor stub

}

GuiNodeHeirarchy::~GuiNodeHeirarchy() {
    // TODO Auto-generated destructor stub


}

void drawNodes(std::shared_ptr<Node> node){

    if(!node) return;
    auto children = node->GetAllChild();

    bool t = ImGui::TreeNode(("##" + node->GetName()).c_str());
    ImGui::SameLine();
    ImGui::Selectable((node->GetName()).c_str(), &node->m_isSelected);

    if(t){


        for(auto& child: children){
            drawNodes(child.lock());
        }
        ImGui::TreePop();
    }
}

void GuiNodeHeirarchy::update(){

    std::shared_ptr<Node> sceneNode = SceneManager::GetCurrentScene();

    ImGui::Begin("Hierarchy");

    drawNodes(sceneNode);

    ImGui::End();
}

} /* namespace Golem */
