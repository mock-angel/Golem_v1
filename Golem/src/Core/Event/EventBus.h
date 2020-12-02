/*
 * EventBus.h
 *
 *  Created on: 05-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_EVENT_EVENTBUS_H_
#define CORE_EVENT_EVENTBUS_H_

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <functional>
#include <list>

#include "Event.h"
#include "Debug.h"
#include "EventCallback.h"
#include "../Layer/Layer.h"

namespace Golem {

class EventBus {
public:
    EventBus();
    virtual ~EventBus();

    void Publish(Event& t_event);
    void Subscribe(EventTypeEnum t_event, std::shared_ptr<IEventCallback>& m_dispacher){
        m_map[t_event].push_back(m_dispacher);
        Debug::log("Subscribe " + std::to_string(t_event));
    }
    void UnSubscribe(EventTypeEnum& t_event, std::shared_ptr<IEventCallback>& m_dispacher){
        m_map[t_event].remove(m_dispacher);
    }

private:
    friend class LayerManager;
    inline bool isCacheEmpty(){return m_callbackListCache == nullptr;}
    inline void updateCache(){
        m_callbackListCache = m_callbackListBuffer;
        m_cacheEventType = m_bufferEventType;
    }
    inline void addListener(std::shared_ptr<Layer>& t_layer){
        m_listeners.push_back(t_layer);
    }
    std::unordered_map<EventTypeEnum, std::list<std::shared_ptr<IEventCallback>>> m_map;

    std::list<std::shared_ptr<Layer>> m_listeners;

    EventTypeEnum m_cacheEventType = EventTypeEnum::None;
    EventTypeEnum m_bufferEventType = EventTypeEnum::None;
    std::list<std::shared_ptr<IEventCallback>>* m_callbackListCache = nullptr;
    std::list<std::shared_ptr<IEventCallback>>* m_callbackListBuffer = nullptr;
};

} /* namespace Golem */

#endif /* CORE_EVENT_EVENTBUS_H_ */
