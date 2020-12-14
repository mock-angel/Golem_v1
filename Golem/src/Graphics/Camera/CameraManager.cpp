/*
 * CameraManager.cpp
 *
 *  Created on: 11-Dec-2020
 *      Author: anantha
 */

#include "CameraManager.h"

namespace Golem {

CameraManager* CameraManager::m_Instance = nullptr;

CameraManager::CameraManager() {
    // TODO Auto-generated constructor stub
    m_Instance = this;
}

CameraManager::~CameraManager() {
    // TODO Auto-generated destructor stub
}

} /* namespace Golem */
