/*
 * Scene.h
 *
 *  Created on: 19-Nov-2020
 *      Author: anantha
 */

#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include <string>
#include <memory>
#include <list>

#include "Node.h"
#include "Core/Resource/Resource.h"

namespace Golem {

class Scene: public Node, public Resource {

public:
    Scene();
    virtual ~Scene();

    inline bool isLoaded(){
        return m_loaded;
    }

    void load();
    void unload();
private:
    std::string m_sceneName = nullptr;
    int m_sceneId = -1;

    std::list<NodeRef> m_nodes;

    bool m_loaded = false;
};

} /* namespace Golem */

#endif /* SCENE_SCENE_H_ */
