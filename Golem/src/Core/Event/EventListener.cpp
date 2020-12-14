/*
 * EventListeners.cpp
 *
 *  Created on: 13-Dec-2020
 *      Author: anantha
 */

#include "EventListener.h"

#include <functional>

#include "EventDispatcher.h"
#include "Debug.h"

namespace Golem {

EventListener::EventListener() {
    // TODO Auto-generated constructor stub

}

EventListener::~EventListener() {
    // TODO Auto-generated destructor stub
}


void KeyboardEventListener::OnEvent(Event& event){
    EventDispatcher eventDispatcher(event);
    //std::function<void(void*)> function;
    eventDispatcher.dispatch<KeyPressedEvent>(GOLEM_MFUN(KeyboardEventListener::OnKeyDown, this));
    eventDispatcher.dispatch<KeyReleasedEvent>(GOLEM_MFUN(KeyboardEventListener::OnKeyUp, this));
}

void MouseEventListener::OnEvent(Event& event){
    EventDispatcher eventDispatcher(event);
    //std::function<void(Event&)> function;

    eventDispatcher.dispatch<MouseMotionEvent>(GOLEM_MFUN(MouseEventListener::OnMouseMove, this));
    eventDispatcher.dispatch<MouseButtonEventDown>(GOLEM_MFUN(MouseEventListener::OnMouseButtonDown, this));
    eventDispatcher.dispatch<MouseButtonEventUp>(GOLEM_MFUN(MouseEventListener::OnMouseButtonUp, this));
    eventDispatcher.dispatch<MouseWheelEvent>(GOLEM_MFUN(MouseEventListener::OnMouseWheel, this));
}

void InputEventListener::OnEvent(Event& event){
    KeyboardEventListener::OnEvent(event);
    MouseEventListener::OnEvent(event);
}

void MouseEventListener::OnMouseMove(MouseMotionEvent& event){
    Debug::log("Move moved");
}

} /* namespace Golem */
