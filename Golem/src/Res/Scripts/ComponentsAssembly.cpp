/*
 * ComponentsAssembly.cpp
 *
 *  Created on: 29-Oct-2020
 *      Author: anantha
 */


#include "ComponentsAssembly.h"

#include "../../Component.h"

#include "CameraScript.h"
#include "SpriteScript.h"
#include "Transform.h"

namespace Golem{

ComponentsAssembly::ComponentsAssembly(){

}

ComponentsAssembly::~ComponentsAssembly(){

}

void ComponentsAssembly::assemble(){
    CameraScript::scriptAdder();
    SpriteScript::scriptAdder();
    Transform::scriptAdder();

}

} /* namespace Golem */
