/*
 * EditorLayer.cpp
 *
 *  Created on: 03-Dec-2020
 *      Author: anantha
 */

#include "EditorLayer.h"

#include "../Core/GUI/GuiNodeHeirarchy.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"
#include "Core/GUI/ImGuiResourceManager.h"
#include "Core/GUI/GUIEditorNodeInspector.h"

#include "DebugGUI.h"
#include "ImGuiGame.h"
#include "ImGuiScene.h"

namespace Golem {

EditorLayer::EditorLayer() {
    // TODO Auto-generated constructor stub
    m_resourceManagerGUI = std::make_shared<ImGuiResourceManager>();
    m_resourceManagerGUI->open();

    m_heirarchyGUI = std::make_shared<GuiNodeHeirarchy>();
    m_heirarchyGUI->open();

    m_nodeInspectorGUI = std::make_shared<GUIEditorNodeInspector>();
    m_nodeInspectorGUI->open();


    m_editorDebugGUI = std::make_shared<DebugGUI>();
    m_editorDebugGUI->open();

    m_editorGameWindowGUI = std::make_shared<ImGuiGame>();
    m_editorGameWindowGUI->open();

    m_editorSceneWindowGUI = std::make_shared<ImGuiScene>();
    m_editorSceneWindowGUI->open();
}

EditorLayer::~EditorLayer() {
    // TODO Auto-generated destructor stub
}

void EditorLayer::update(){
    return;
    ImGuiIO& io = ImGui::GetIO();

    //Docking Space.
    ImGuiWindowFlags docker_window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    //Fullscreen Docker.
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->GetWorkPos());
    ImGui::SetNextWindowSize(viewport->GetWorkSize());
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    //All window color changes.


    docker_window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    docker_window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

    //Pass-through and transparent background.
    dockspace_flags |= ImGuiDockNodeFlags_PassthruCentralNode;
    docker_window_flags |= ImGuiWindowFlags_NoBackground;

    ImGui::Begin("Editor DockSpace", &m_isOpen, docker_window_flags);
    ImGui::PopStyleVar(3);


    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

    ImGui::End();
    /*
    if(ImGui::GetWindowSize().x < 150) ImGui::SetWindowSize(ImVec2(150, ImGui::GetWindowSize().y));
    if(ImGui::GetWindowSize().y < io.DisplaySize.y || ImGui::GetWindowSize().y > io.DisplaySize.y) ImGui::SetWindowSize(ImVec2(ImGui::GetWindowSize().x, io.DisplaySize.y));
    */

    m_resourceManagerGUI->update();
    m_nodeInspectorGUI->update();
    m_heirarchyGUI->update();

    m_editorDebugGUI->update();

    m_editorGameWindowGUI->update();
    m_editorSceneWindowGUI->update();

}



} /* namespace Golem */
