/*
 * EditorEvents.h
 *
 *  Created on: 13-Dec-2020
 *      Author: anantha
 */

#ifndef EDITOR_EDITOREVENT_H_
#define EDITOR_EDITOREVENT_H_

#include "Core/Event/Event.h"

namespace Golem {

class EditorEvent: public Event {
public:
    EditorEvent();
    ~EditorEvent();
};

class EditorMouseMovedEvent : public MouseMotionEvent{

public:
    EVENT_CLASS_TYPE(EventTypeEnum::MouseButtonEventType)
    EVENT_CLASS_CATEGORY(EventCategory::MouseEventCategory | EventCategory::InputEventCategory | EditorEventCategory)
};

} /* namespace Golem */

#endif /* EDITOR_EDITOREVENT_H_ */
