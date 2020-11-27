/*
 * Resource.cpp
 *
 *  Created on: 22-Nov-2020
 *      Author: anantha
 */

#include "Resource.h"

#include "Utils/FileUtils.h"

namespace Golem {

void Resource::prepare(){
    FileUtils::loadFile(m_path, &m_data);
    onPrepare();
    m_loadState = LOADSTATE_PREPARED;
}

} /* namespace Golem */
