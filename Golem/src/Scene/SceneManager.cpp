/*
 * SceneManager.cpp
 *
 *  Created on: 19-Nov-2020
 *      Author: anantha
 */

#include "SceneManager.h"

namespace Golem {

SceneManager* SceneManager::m_Instance = nullptr;

SceneManager::SceneManager() {
    // TODO Auto-generated constructor stub
    m_Instance = this;
}

SceneManager::~SceneManager() {
    // TODO Auto-generated destructor stub
    if(m_Instance == this)
        m_Instance = nullptr;
}

} /* namespace Golem */
