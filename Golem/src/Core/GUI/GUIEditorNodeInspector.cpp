/*
 * EditorNodeInspector.cpp
 *
 *  Created on: 03-Dec-2020
 *      Author: anantha
 */

#include "GUIEditorNodeInspector.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"
#include "Scene/SceneManager.h"

namespace Golem {

GUIEditorNodeInspector::GUIEditorNodeInspector() {
    // TODO Auto-generated constructor stub

}

GUIEditorNodeInspector::~GUIEditorNodeInspector() {
    // TODO Auto-generated destructor stub
}

void GUIEditorNodeInspector::update(){
    ImGui::Begin("Node Inspector");

    ImGui::End();

}

} /* namespace Golem */
