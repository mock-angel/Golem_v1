/*
 * ImGuiResourceManager.h
 *
 *  Created on: 20-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_GUI_IMGUIRESOURCEMANAGER_H_
#define CORE_GUI_IMGUIRESOURCEMANAGER_H_

#include <filesystem>
#include <list>

#include "ImGuiWindow.h"

namespace Golem {

class ImGuiResourceManager : public ImGuiWindow {
public:
    ImGuiResourceManager();
    ~ImGuiResourceManager();

    void update();

    std::list<bool> directoryOpenedList;
};

} /* namespace Golem */

#endif /* CORE_GUI_IMGUIRESOURCEMANAGER_H_ */
