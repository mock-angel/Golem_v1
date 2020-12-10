/*
 * DebugGUI.cpp
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#include "DebugGUI.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"

namespace Golem {

DebugGUI::DebugGUI() {
    // TODO Auto-generated constructor stub

}

DebugGUI::~DebugGUI() {
    // TODO Auto-generated destructor stub
}

void DebugGUI::update(){

    ImGui::Begin("Debug");
    ImGui::End();

}

} /* namespace Golem */
