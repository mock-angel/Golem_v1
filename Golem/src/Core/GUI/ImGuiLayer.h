/*
 * ImGuiLayer.h
 *
 *  Created on: 13-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_GUI_IMGUILAYER_H_
#define CORE_GUI_IMGUILAYER_H_

#include <list>
#include <memory>

#include "../Layer/Layer.h"
#include "../Gui.h"
#include "ImGuiWindow.h"
#include "ProjectManagerImGui.h"
#include "Debug.h"

namespace Golem {

class ImGuiLayer : public Layer {
public:
    ImGuiLayer(): Layer(true, false, true){}
    virtual ~ImGuiLayer();

    void onAttach() override;

    void onDetach() override{

    }

    void update(){
        for(auto& imguiWindow: m_imGuiWindows)
            imguiWindow->update();

        //Debug::log("ImGuiLayer::update()");
        Gui::RenderGUI();
    }

    void onEvent(Event& t_event);
private:
    std::list<std::shared_ptr<ImGuiWindow>> m_imGuiWindows;

    void SetDarkThemeColors();
};

} /* namespace Golem */

#endif /* CORE_GUI_IMGUILAYER_H_ */
