/*
 * ComponentsAssembly.cpp
 *
 *  Created on: 29-Oct-2020
 *      Author: anantha
 */


#include "ComponentsAssembly.h"

#include "../../ComponentOld.h"
#include "CameraScript.h"
#include "SpriteScript.h"
#include "Transform.h"
#include "Editor/EditorCameraScript.h"

namespace Golem{

ComponentsAssembly::ComponentsAssembly(){

}

ComponentsAssembly::~ComponentsAssembly(){

}

void ComponentsAssembly::assemble(){
    CameraScript::scriptAdder();
    SpriteScript::scriptAdder();
    Transform::scriptAdder();
    EditorCameraScript::scriptAdder();
}

} /* namespace Golem */
