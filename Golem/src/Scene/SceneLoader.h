/*
 * SceneLoader.h
 *
 *  Created on: 01-Dec-2020
 *      Author: anantha
 */

#ifndef SCENE_SCENELOADER_H_
#define SCENE_SCENELOADER_H_

#include <string>
#include <memory>

namespace Golem {

class Node;

class SceneLoader {
public:
    SceneLoader();
    ~SceneLoader();

    std::shared_ptr<Node> loadScene(const std::string& path);
};

} /* namespace Golem */

#endif /* SCENE_SCENELOADER_H_ */
