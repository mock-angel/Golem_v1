/*
 * Event.h
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_EVENT_EVENT_H_
#define CORE_EVENT_EVENT_H_

#include <functional>
#include <SDL2/SDL.h>

#include <stdint.h>

#include "EventType.h"

namespace Golem {

enum EventTypeEnum{
    None = 0,
    WindowEventType,

    KeyDownEventType,
    KeyUpEventType,

    MouseMotionEventType,
    MouseButtonEventType,
    MouseWheelEventType,

    GameEventType,
    CustomEventType
};

#define BIT(num) num << 2

enum EventCategory{
    MouseEventCategory = BIT(1),
    KeyboardEventCategory = BIT(2),
    InputEventCategory = BIT(3),
    CustomEventCategory = BIT(4),
    WindowEventCategory = BIT(5),
    EditorEventCategory = BIT(6),
};

#define EVENT_CLASS_TYPE(type) \
        static EventTypeEnum GetStaticEventType() {return  type;}\
        virtual EventTypeEnum GetEventType() const {return  type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}


class Event{
    //friend class EventDispacher;
public:
    Event(){};
    virtual ~Event(){};

    static EventTypeEnum GetStaticEventType(){return EventTypeEnum::None;}
    virtual EventTypeEnum GetEventType() const = 0;
    virtual int GetCategoryFlags() const = 0;
    /*virtual EventTypeEnum GetEventType() const{
        return type;
    }*/

protected:
    EventTypeEnum m_Type = EventTypeEnum::None;
};

class KeyEvent: public Event{
public:
    inline int GetKeyCode() const { return m_KeyCode;}
    inline int GetRepeatCount() const { return m_RepeatCount;}

    EVENT_CLASS_TYPE(EventTypeEnum::KeyDownEventType)
protected:
    KeyEvent(int keyCode, int repeatCount) : m_KeyCode(keyCode), m_RepeatCount(repeatCount){}

    int m_KeyCode;
    int m_RepeatCount;
};

class KeyPressedEvent: public KeyEvent{
public:
    KeyPressedEvent(int keyCode, int repeatCount)
        : KeyEvent(keyCode, repeatCount) {}
    EVENT_CLASS_TYPE(EventTypeEnum::KeyDownEventType)
    EVENT_CLASS_CATEGORY( EventCategory::KeyboardEventCategory | EventCategory::InputEventCategory )
protected:

private:

};

class KeyReleasedEvent: public KeyEvent{
public:
    KeyReleasedEvent(int keyCode, int repeatCount)
        : KeyEvent(keyCode, repeatCount){}
    EVENT_CLASS_TYPE(EventTypeEnum::KeyUpEventType)
    EVENT_CLASS_CATEGORY( EventCategory::KeyboardEventCategory | EventCategory::InputEventCategory )
protected:
};

struct WindowEvent: public Event{
    WindowEvent(){m_Type = EventTypeEnum::WindowEventType;}
    SDL_Event sdl_event;

    EVENT_CLASS_TYPE(EventTypeEnum::WindowEventType)

};

class WindowResizedEvent: public WindowEvent{
public:
    WindowResizedEvent(int t_width, int t_height)
        : m_width(t_width), m_height(t_height){m_Type = EventTypeEnum::WindowEventType;}
    EVENT_CLASS_CATEGORY(EventCategory::WindowEventCategory)

    inline int getWidth(){return m_width;}
    inline int getHeight(){return m_height;}
private:
    int m_width;
    int m_height;
};

class EventCallbackBase{
public:
    EventCallbackBase();
    virtual ~EventCallbackBase();

    virtual void call() = 0;

};

class MouseMotionEvent : public Event{
public:
    MouseMotionEvent(float x, float y)
        : m_MouseX(x), m_MouseY(y) {}

    inline float GetX() const { return m_MouseX; }
    inline float GetY() const { return m_MouseY; }

    EVENT_CLASS_TYPE(EventTypeEnum::MouseMotionEventType)
    EVENT_CLASS_CATEGORY(EventCategory::MouseEventCategory | EventCategory::InputEventCategory)
private:
    float m_MouseX, m_MouseY;

};

class MouseButtonEvent : public Event{
public:
    MouseButtonEvent(int buttonInt)
        : m_Button(buttonInt) {}

    inline float GetButton() const { return m_Button; }

    EVENT_CLASS_TYPE(EventTypeEnum::MouseButtonEventType)
    EVENT_CLASS_CATEGORY(EventCategory::MouseEventCategory | EventCategory::InputEventCategory)

private:
    int m_Button;
};

class MouseButtonEventDown : public MouseButtonEvent{
public:
    MouseButtonEventDown(int buttonInt)
          : MouseButtonEvent(buttonInt) {}
};

class MouseButtonEventUp : public MouseButtonEvent{
public:
    MouseButtonEventUp(int buttonInt)
          : MouseButtonEvent(buttonInt) {}
};

class MouseWheelEvent : public Event{
public:
    MouseWheelEvent(int t_x, int t_y)
          : x(t_x), y(t_y) {}
    inline int GetX(){ return x; }
    inline int GetY(){ return y; }
    EVENT_CLASS_TYPE(EventTypeEnum::MouseWheelEventType)
    EVENT_CLASS_CATEGORY(EventCategory::MouseEventCategory | EventCategory::InputEventCategory)
private:
    int x, y;
};


} /* namespace Golem */
#endif /* CORE_EVENT_EVENT_H_ */
