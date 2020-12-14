/*
 * EventListeners.h
 *
 *  Created on: 13-Dec-2020
 *      Author: anantha
 */

#ifndef CORE_EVENT_EVENTLISTENER_H_
#define CORE_EVENT_EVENTLISTENER_H_

#define GOLEM_MFUN(Fun, Obj) std::bind(&Fun, Obj, std::placeholders::_1)

#include "Debug.h"

namespace Golem {

class Event;
class KeyPressedEvent;
class KeyReleasedEvent;
class MouseMotionEvent;
class MouseButtonEventDown;
class MouseButtonEventUp;
class MouseWheelEvent;

class EventListener {
public:
    EventListener();
    ~EventListener();
};

class KeyboardEventListener : public EventListener{
public:
    KeyboardEventListener(){}
    virtual ~KeyboardEventListener(){}

    virtual void OnKeyDown(KeyPressedEvent& event){ ; }
    virtual void OnKeyUp(KeyReleasedEvent& event){ ; }
protected:
    friend class EventListenerHandler;
    void OnEvent(Event& event);
};

class MouseEventListener : public EventListener {
public:
    MouseEventListener(){}
    virtual ~MouseEventListener(){}

    virtual void OnMouseMove(MouseMotionEvent& event);
    virtual void OnMouseButtonDown(MouseButtonEventDown& event){ ; }
    virtual void OnMouseButtonUp(MouseButtonEventUp& event){ ; }
    virtual void OnMouseWheel(MouseWheelEvent& event){ ; }

protected:
    friend class EventListenerHandler;
    void OnEvent(Event& event);
};

class InputEventListener : public KeyboardEventListener, public MouseEventListener{
protected:
    void OnEvent(Event& event);
    friend class EventListenerHandler;
};


class EventListenerHandler{

};

} /* namespace Golem */

#endif /* CORE_EVENT_EVENTLISTENER_H_ */
