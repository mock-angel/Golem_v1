/*
 * Renderable.cpp
 *
 *  Created on: 24-Sep-2020
 *      Author: anantha
 */

#include "Renderable.h"
#include "../Game.h"
#include "ComponentOldController.h"

namespace Golem {

Renderable::Renderable() {
    // TODO Auto-generated constructor stub
    m_componentController = Game::getComponentController();
}

Renderable::~Renderable() {
    // TODO Auto-generated destructor stub
}

void Renderable::enableRenders(bool value){
    renderComponent = value;
}

} /* namespace Golem */
