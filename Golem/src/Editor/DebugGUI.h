/*
 * DebugGUI.h
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#ifndef EDITOR_DEBUGGUI_H_
#define EDITOR_DEBUGGUI_H_

#include "Core/GUI/ImGuiWindow.h"

namespace Golem {

class DebugGUI : public ImGuiWindow {
public:
    DebugGUI();
    ~DebugGUI();

    void update();
};

} /* namespace Golem */

#endif /* EDITOR_DEBUGGUI_H_ */
