/*
 * EditorNodeInspector.h
 *
 *  Created on: 03-Dec-2020
 *      Author: anantha
 */

#ifndef CORE_GUI_GUIEDITORNODEINSPECTOR_H_
#define CORE_GUI_GUIEDITORNODEINSPECTOR_H_

#include "ImGuiWindow.h"

namespace Golem {

class GUIEditorNodeInspector: public ImGuiWindow {
public:
    GUIEditorNodeInspector();
    ~GUIEditorNodeInspector();

    void update();
};

} /* namespace Golem */

#endif /* CORE_GUI_GUIEDITORNODEINSPECTOR_H_ */
