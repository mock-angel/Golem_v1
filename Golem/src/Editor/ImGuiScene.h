/*
 * ImGuiGame.h
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#ifndef EDITOR_IMGUISCENE_H_
#define EDITOR_IMGUISCENE_H_

#include "Core/GUI/ImGuiWindow.h"

#include "Graphics/Camera/Camera.h"
#include "Core/Event/EventListener.h"

class Event;

namespace Golem {

class ImGuiScene : public ImGuiWindow, public InputEventListener{
public:
    ImGuiScene();
    ~ImGuiScene();

    void update();

    void OnEvent(Event& event);

    virtual void OnKeyDown(KeyPressedEvent& event);
    virtual void OnKeyUp(KeyReleasedEvent& event);
    virtual void OnMouseMove(MouseMotionEvent& event);
    virtual void OnMouseButtonDown(MouseButtonEventDown& event);
    virtual void OnMouseButtonUp(MouseButtonEventUp& event);
    virtual void OnMouseWheel(MouseWheelEvent& event);

private:
    std::shared_ptr<Camera> m_editorCamera;
    int regionAvailX = 1;
    int regionAvailY = 1;
};

} /* namespace Golem */

#endif /* EDITOR_IMGUIGAME_H_ */
