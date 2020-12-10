/*
 * ImGuiGame.h
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#ifndef EDITOR_IMGUISCENE_H_
#define EDITOR_IMGUISCENE_H_

#include "Core/GUI/ImGuiWindow.h"

#include "Graphics/FrameBuffer.h"

namespace Golem {

class ImGuiScene : public ImGuiWindow {
    FrameBuffer frameBuffer;
public:
    ImGuiScene();
    ~ImGuiScene();

    void update();
};

} /* namespace Golem */

#endif /* EDITOR_IMGUIGAME_H_ */
