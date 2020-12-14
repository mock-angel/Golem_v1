/*
 * ComponentTypeHolder.h
 *
 *  Created on: 26-Oct-2020
 *      Author: anantha
 */

#ifndef COMPONENTS_COMPONENTOLDTYPEHOLDER_H_
#define COMPONENTS_COMPONENTOLDTYPEHOLDER_H_

#include <map>

#include "ComponentOld.h"

namespace Golem {

class ComponentTypeHolder {
public:
    ComponentTypeHolder();
    virtual ~ComponentTypeHolder();

    template<typename T>
    static bool addScript(){
        m_Instance->m_components[T::classname()] = std::make_shared<T>();
        return true;
    }

    inline static ComponentTypeHolder* getInstance(){
        return m_Instance;
    }
    static std::shared_ptr<ComponentOld> getComponent(const std::string& className);
private:
    static ComponentTypeHolder* m_Instance;
    std::map<std::string, std::shared_ptr<ComponentOld>> m_components;
};

} /* namespace Golem */

#endif /* COMPONENTS_COMPONENTOLDTYPEHOLDER_H_ */
