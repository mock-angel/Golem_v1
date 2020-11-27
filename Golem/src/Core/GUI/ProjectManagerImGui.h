/*
 * ProjectManagerImGui.h
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_GUI_PROJECTMANAGERIMGUI_H_
#define CORE_GUI_PROJECTMANAGERIMGUI_H_

#include "ImGuiWindow.h"
#include "../ProjectManager/ProjectManager.h"

struct Rect {
    float x;
    float y;
    float w;
    float h;
};


namespace Golem {

class ProjectManagerImGui : public ImGuiWindow {
public:
    ProjectManagerImGui();
    virtual ~ProjectManagerImGui();

    void update();
    void displayCreateProjectWindow();

private:

    Rect r{ 0.f, 0.f, 0.f, 0.f };
    std::array<float, 4> arr2 = { 0 };

    bool createProjectWindow = false;
    ProjectManager* m_projectManager = nullptr;

    char m_projectName[128] = "\0";
    char m_projectDir[128] = "\0";
};

} /* namespace Golem */

#endif /* CORE_GUI_PROJECTMANAGERIMGUI_H_ */
