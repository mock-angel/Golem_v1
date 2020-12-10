/*
 * ImGuiGame.cpp
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#include "ImGuiScene.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"

namespace Golem {

ImGuiScene::ImGuiScene() {
    // TODO Auto-generated constructor stub
    frameBuffer.create(720, 720);
    frameBuffer.bind();
    frameBuffer.unbind();
}

ImGuiScene::~ImGuiScene() {
    // TODO Auto-generated destructor stub
}


void ImGuiScene::update(){

    int tex = 1;

    ImGui::Begin("Scene");

    ImGui::BeginChild("GameRender");
    ImVec2 wsize = ImGui::GetWindowSize();
    // Need to invert the V from the UV.
    ImGui::Image((ImTextureID)tex, wsize, ImVec2(0, 1), ImVec2(1, 0));

    ImGui::EndChild();

    ImGui::End();

}


} /* namespace Golem */
