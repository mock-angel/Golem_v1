/*
 * ProjectManagerImGui.cpp
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#include "ProjectManagerImGui.h"

#include <filesystem>
#include <unistd.h>
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"
#include "Window.h"


namespace ImGui {

bool InputRect(const char* label, Rect* rectPtr,
    int decimal_precision = -1, ImGuiInputTextFlags extra_flags = 0)
{
    ImGui::PushID(label);
    ImGui::BeginGroup();

    bool valueChanged = false;

    std::array<float*, 4> arr = { &rectPtr->x, &rectPtr->y,
                                  &rectPtr->w, &rectPtr->h };

    for (auto& elem : arr) {
        ImGui::PushID(elem);
        ImGui::PushItemWidth(64.f);
        valueChanged |= ImGui::InputFloat("##arr", elem, 0, 0,
                "%f", extra_flags);

        ImGui::PopID();
        ImGui::SameLine();
    }

    ImGui::SameLine();
    ImGui::TextUnformatted(label);
    ImGui::EndGroup();

    ImGui::PopID(); // pop label id;

    return valueChanged;
}

static auto vector_getter = [](void* vec, int idx, const char** out_text)
{
    auto& vector = *static_cast<std::vector<std::string>*>(vec);
    if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
    *out_text = vector.at(idx).c_str();
    return true;
};

bool Combo(const char* label, int* currIndex, std::vector<std::string>& values)
{
    if (values.empty()) { return false; }
    return Combo(label, currIndex, vector_getter,
        static_cast<void*>(&values), values.size());
}

bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values)
{
    if (values.empty()) { return false; }
    return ListBox(label, currIndex, vector_getter,
        static_cast<void*>(&values), values.size());
}

}


namespace Golem {

ProjectManagerImGui::ProjectManagerImGui() {
    strcpy(m_projectDir, get_current_dir_name());
}

ProjectManagerImGui::~ProjectManagerImGui() {
    // TODO Auto-generated destructor stub
}

void ProjectManagerImGui::update(){

    if(m_projectManager == nullptr) m_projectManager = ProjectManager::getInstance();
    if(!isOpen() || m_projectManager == nullptr) return;

    ImVec2 pos{0.f, 0.f};//, pivot{0.5f, 0.5f};

    Window* windowInstance = Window::getWindow();
    ImVec2 size(windowInstance->getWidth(), windowInstance->getHeight());

    ImGui::SetNextWindowPos(pos, ImGuiCond_Once);
    ImGui::SetNextWindowSize(size);


    //Debug::log("Entered WIndow IMGUI ProjectManagerImGUI");
    ImGui::Begin("Golem Engine - Project Manager", NULL, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoTitleBar);

    static char name[128] = "";
    static char dir[128] = "";

    ImGui::Columns(2, NULL, false);

    ImGui::Text("Golem Engine - Project Manager");
    ImGui::NextColumn();

    std::string versionText = "Golem v2020.11.18r1";

    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(versionText.c_str()).x \
        - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x);
    ImGui::Text(versionText.c_str());

    ImGui::Columns(1);

    int currentwidth = ImGui::GetWindowSize().x;
    int size_ = ImGui::CalcTextSize("Project List").x + ImGui::CalcTextSize("Templates").x;

    ImGui::BeginGroup();


    int vt = ImGui::GetCursorPosY();
    ImGui::BeginTabBar("##noneBar0");
    ImGui::EndTabBar();

    ImGui::SetCursorPosX(currentwidth/2 - size_/2 - 10);
    ImGui::SetCursorPosY(vt);
    ImGui::BeginTabBar("Project TabBar");

    if (ImGui::BeginTabItem("Project List")){

        ImGui::Columns(2, NULL, false);
        ImGui::SetColumnWidth(0,currentwidth-200);
        ImGui::SetColumnWidth(1,200);

        const auto& v = m_projectManager->getProjectList();
        ImVec2 v2 = ImVec2(ImGui::GetContentRegionAvailWidth(), 0);



        for(auto& var: v) {
            if(ImGui::Button((var.name + "\n" + var.dir).c_str(), v2)){
                m_projectManager->openProject(var);
                if(m_projectManager->isProjectOpened()) close();
            }
        }


        ImGui::NextColumn();

        ImVec2 buttonSize = ImVec2(100, 30);
        int xValueForCursor = ImGui::GetCursorPosX() + ImGui::GetContentRegionAvailWidth()/2 - buttonSize.x/2;
        ImGui::SetCursorPosX(xValueForCursor);

        ImGui::PushStyleColor(ImGuiCol_Button, ImColor(100, 100, 100).Value);

        if(ImGui::Button("Run", buttonSize)) {
            createProjectWindow = true;//m_projectManager.addProject(name, dir);
            ImGui::SetWindowFocus("Create Project");
        }

        ImGui::SetCursorPosX(xValueForCursor);
        if(ImGui::Button("New Project", buttonSize));
        ImGui::SetCursorPosX(xValueForCursor);
        if(ImGui::Button("Add", buttonSize));
        ImGui::SetCursorPosX(xValueForCursor);
        if(ImGui::Button("Rename", buttonSize));
        ImGui::SetCursorPosX(xValueForCursor);
        if(ImGui::Button("Remove", buttonSize));
        ImGui::PopStyleColor();
        ImGui::Columns(1);

        //ImGui::InputFloat4("Array", arr2.data());
        //ImGui::InputRect("Rect", &r);

        ImGui::EndTabItem();
    }

    if(ImGui::BeginTabItem("Templates")){
        ImGui::EndTabItem();
    }

    ImGui::EndTabBar();
    ImGui::EndGroup();

    ImGui::End();

    displayCreateProjectWindow();
}


void ProjectManagerImGui::displayCreateProjectWindow(){

    if(!createProjectWindow) return;

    ImGui::Begin("Create Project", &createProjectWindow);

    ImGui::Text("Project Name");
    ImGui::InputText("##Project Name", m_projectName, 128);
    if(ImGui::Button("Create Folder")){
            std::filesystem::create_directories(
                    std::string(m_projectDir)+"/"+std::string(m_projectName));

            strcat(m_projectDir, ("/"+std::string(m_projectName)).c_str());
    }
    ImGui::Text("Project Directory");
    ImGui::InputText("##Project Directory", m_projectDir, 128);


    bool dirEmpty = false;
    if(std::filesystem::is_directory(m_projectDir))
        dirEmpty = std::filesystem::is_empty(m_projectDir);


    if(!dirEmpty) ImGui::PushStyleColor(ImGuiCol_Button, ImColor(100, 100, 100).Value);
    else ImGui::PushStyleColor(ImGuiCol_MenuBarBg, ImColor(100, 100, 100).Value);

    if(ImGui::Button("Create Project") && dirEmpty)
        m_projectManager->createProject(ProjectData(m_projectName, m_projectDir));

    ImGui::PopStyleColor();

    ImGui::End();


}


} /* namespace Golem */
