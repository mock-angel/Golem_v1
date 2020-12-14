/*
 * Component.cpp
 *
 *  Created on: 18-Aug-2020
 *      Author: anantha
 */

#include "ComponentOld.h"

#include <assert.h>

#include "Debug.h"

namespace Golem {

ComponentOld::ComponentOld() {
    // TODO Auto-generated constructor stub

}

ComponentOld::~ComponentOld() {
    // TODO Auto-generated destructor stub
}


void ComponentOld::enableUpdates(bool value){
    updateComponent = value;
}

void ComponentOld::Start(){

}

void ComponentOld::render(){
    Debug::log("Component::render() executed");
}

void ComponentOld::update(){

}

std::weak_ptr<Node> ComponentOld::getGameObject(){

    assert(!parentNode.expired());
    return parentNode;
}

void ComponentOld::setOwner(std::weak_ptr<Node> t_node){
    parentNode = t_node;
}

} /* namespace Golem */
