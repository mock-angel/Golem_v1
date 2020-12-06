/*
 * GuiHeirarchy.h
 *
 *  Created on: 03-Dec-2020
 *      Author: anantha
 */

#ifndef CORE_GUI_GUINODEHEIRARCHY_H_
#define CORE_GUI_GUINODEHEIRARCHY_H_

#include "ImGuiWindow.h"

#include <list>

namespace Golem {

class NodeTree{
    std::list<NodeTree> trees;
};

class GuiNodeHeirarchy  : public ImGuiWindow {
public:
    GuiNodeHeirarchy();
    ~GuiNodeHeirarchy();

    void update();
};

} /* namespace Golem */

#endif /* CORE_GUI_GUINODEHEIRARCHY_H_ */
