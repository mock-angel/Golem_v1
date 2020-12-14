/*
 * EventBus.cpp
 *
 *  Created on: 05-Nov-2020
 *      Author: anantha
 */

#include "EventBus.h"

namespace Golem {

EventBus::EventBus() {
    // TODO Auto-generated constructor stub
}

EventBus::~EventBus() {
    // TODO Auto-generated destructor stub
}

void EventBus::Publish(Event& t_event){

    m_bufferEventType = t_event.GetEventType();

    //Debug::log("gotten event type");
    if(!isCacheEmpty() && m_bufferEventType == m_cacheEventType)
        m_callbackListBuffer = m_callbackListCache;

    else if(m_map.find(m_bufferEventType) != m_map.end())
        m_callbackListBuffer = &m_map[m_bufferEventType];

    else {
        m_bufferEventType = EventTypeEnum::None;
        m_callbackListBuffer = nullptr;
    }

    if(m_callbackListBuffer)
        for(std::shared_ptr<IEventCallback>& callback: *m_callbackListBuffer) callback->call(t_event);
    for(std::shared_ptr<Layer>& layer: m_listeners)  layer->onEvent(t_event);


    updateCache();
}

} /* namespace Golem */
