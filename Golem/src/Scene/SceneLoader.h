/*
 * SceneLoader.h
 *
 *  Created on: 01-Dec-2020
 *      Author: anantha
 */

#ifndef SCENE_SCENELOADER_H_
#define SCENE_SCENELOADER_H_

#include <string>

namespace Golem {

class SceneLoader {
public:
    SceneLoader();
    ~SceneLoader();

    void loadScene(const std::string& path);
};

} /* namespace Golem */

#endif /* SCENE_SCENELOADER_H_ */
