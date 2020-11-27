/*
 * ImGuiLayer.cpp
 *
 *  Created on: 13-Nov-2020
 *      Author: anantha
 */

#include "ImGuiLayer.h"

#include "ImGuiResourceManager.h"

namespace Golem {

ImGuiLayer::~ImGuiLayer() {
    // TODO Auto-generated destructor stub
}



void ImGuiLayer::onAttach() {
    auto projectManagerWindow = std::make_shared<ProjectManagerImGui>();
    m_imGuiWindows.push_back(projectManagerWindow);
    projectManagerWindow->open();

    auto resourceManagerWindow = std::make_shared<ImGuiResourceManager>();
    m_imGuiWindows.push_back(resourceManagerWindow);
    resourceManagerWindow->open();

}

} /* namespace Golem */
