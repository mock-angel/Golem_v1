/*
 * ImGuiGame.h
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#ifndef EDITOR_IMGUIGAME_H_
#define EDITOR_IMGUIGAME_H_

#include "Core/GUI/ImGuiWindow.h"

namespace Golem {

class ImGuiGame : public ImGuiWindow {
public:
    ImGuiGame();
    ~ImGuiGame();

    void update();
};

} /* namespace Golem */

#endif /* EDITOR_IMGUIGAME_H_ */
