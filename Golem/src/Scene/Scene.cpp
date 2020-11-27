/*
 * Scene.cpp
 *
 *  Created on: 19-Nov-2020
 *      Author: anantha
 */

#include "Scene.h"

namespace Golem {

void Scene::unload(){
    for(auto& nodeRef : m_nodes)
        Node::Destroy(nodeRef);
}

} /* namespace Golem */
