/*
 * ComponentTypeHolder.cpp
 *
 *  Created on: 26-Oct-2020
 *      Author: anantha
 */

#include "ComponentTypeHolder.h"

#include "Debug.h"

namespace Golem {

ComponentTypeHolder* ComponentTypeHolder::m_Instance = nullptr;

ComponentTypeHolder::ComponentTypeHolder() {
    // TODO Auto-generated constructor stub
    m_Instance = this;
}

ComponentTypeHolder::~ComponentTypeHolder() {
    // TODO Auto-generated destructor stub
}

std::shared_ptr<Component> ComponentTypeHolder::getComponent(const std::string& className){
    if(m_Instance == nullptr) Debug::log("ComponentTypeHolder::m_Instance is nullptr");

    if(m_Instance->m_components.find(className) != m_Instance->m_components.end()) {
        return (m_Instance->m_components[className]);
    }
    else {

        Debug::log("Requested Component type not found." + std::to_string(m_Instance->m_components.size()));
        return nullptr;
    }
}

/*
static void ComponentTypeHolder::addScript(Component component){

}*/


} /* namespace Golem */
