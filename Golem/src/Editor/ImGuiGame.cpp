/*
 * ImGuiGame.cpp
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#include "ImGuiGame.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"

namespace Golem {

ImGuiGame::ImGuiGame() {
    // TODO Auto-generated constructor stub

}

ImGuiGame::~ImGuiGame() {
    // TODO Auto-generated destructor stub
}


void ImGuiGame::update(){

    ImGui::Begin("Game");
    ImGui::End();

}


} /* namespace Golem */
