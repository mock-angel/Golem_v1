/*
 * ImGuiLayer.cpp
 *
 *  Created on: 13-Nov-2020
 *      Author: anantha
 */

#include "ImGuiLayer.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"
#include "ImGuiResourceManager.h"
#include "Editor/EditorLayer.h"
#include "GuiNodeHeirarchy.h"

namespace Golem {

ImGuiLayer::~ImGuiLayer() {
    // TODO Auto-generated destructor stub
}



void ImGuiLayer::onAttach() {

    //code from : https://github.com/TheCherno/Hazel/blob/master/Hazel/src/Hazel/ImGui/ImGuiLayer.cpp
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    //io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    SetDarkThemeColors();

    auto projectManagerWindow = std::make_shared<ProjectManagerImGui>();
    m_imGuiWindows.push_back(projectManagerWindow);
    projectManagerWindow->open();

    //auto resourceManagerWindow = std::make_shared<ImGuiResourceManager>();
    //m_imGuiWindows.push_back(resourceManagerWindow);
    //resourceManagerWindow->open();

    //auto heirarchyWindow = std::make_shared<GuiHeirarchy>();
    //m_imGuiWindows.push_back(heirarchyWindow );
    //heirarchyWindow ->open();

    auto editorWindow = std::make_shared<EditorLayer>();
    m_imGuiWindows.push_back(editorWindow );
    editorWindow ->open();
}

void ImGuiLayer::SetDarkThemeColors()
{
    auto& colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.105f, 0.11f, 1.0f };

    // Headers
    colors[ImGuiCol_Header] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
    colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
    colors[ImGuiCol_HeaderActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

    // Buttons
    colors[ImGuiCol_Button] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
    colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
    colors[ImGuiCol_ButtonActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

    // Frame BG
    colors[ImGuiCol_FrameBg] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
    colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
    colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

    // Tabs
    colors[ImGuiCol_Tab] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
    colors[ImGuiCol_TabHovered] = ImVec4{ 0.38f, 0.3805f, 0.381f, 1.0f };
    colors[ImGuiCol_TabActive] = ImVec4{ 0.28f, 0.2805f, 0.281f, 1.0f };
    colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };

    // Title
    colors[ImGuiCol_TitleBg] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
    colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

    //My Custom Header Mods.
    colors[ImGuiCol_Header] = ImVec4{ 68/255.f, 68/255.f, 68/255.f, 1.0f };
    colors[ImGuiCol_HeaderHovered] = ImVec4{ 78/255.f, 78/255.f, 79/255.f, 1.0f };
    colors[ImGuiCol_HeaderActive] = ImVec4{ 68/255.f, 68/255.f, 69/255.f, 1.0f };
    //ImGui::PushStyleColor(ImGuiCol_Header, {68, 68, 69, 255});
    //ImGui::PushStyleColor(ImGuiCol_HeaderHovered, {78, 78, 79, 185});
    //ImGui::PushStyleColor(ImGuiCol_HeaderActive, {68, 68, 69, 255});
}

} /* namespace Golem */
