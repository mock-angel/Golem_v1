/*
 * GameWindow.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include "GameWindow.h"

#include <iostream>
#include <memory>

#include "Debug.h"
#include "Node.h"
#include "Component.h"
#include "Core/Math/Vector2.h"
#include "Graphics/Shader/Shader.h"
#include "Res/Scripts/SpriteScript.h"
#include "Res/Scripts/Transform.h"
#include "Res/Scripts/CameraScript.h"
#include "imgui.h"
#include "Components/ComponentTypeHolder.h"

GameWindow::GameWindow() {
    // TODO Auto-generated constructor stub
    std::cout << "hello" << std::endl;

    Golem::Vector2 vec(0, 1.999);

    //Golem::Node* node = new Golem::Node(this);
    //getNodeHandler()->addNode(node);
}

GameWindow::~GameWindow() {
    // TODO Auto-generated destructor stub
}

void GameWindow::awake(){
    std::cout << "GameWindow::awake executing"<<std::endl;


    //compo->setShader(shader);
    Golem::Node::print("starting call to Node::Instantiate()");
    auto n = Golem::Node::Instantiate();

    //auto compo = (std::make_shared<Golem::SpriteScript>());
    //n.lock()->addComponent(compo);
    //Golem::Node::Instantiate().lock()->addComponent(compo1);
    Golem::Node::print("ending call to Node::Instantiate()");

    std::shared_ptr<Golem::Component> transformCompo = Golem::ComponentTypeHolder::getComponent("Transform")->createNewShared();
    n.lock()->addComponent(transformCompo);

    std::shared_ptr<Golem::Component> cameraCompo = std::dynamic_pointer_cast<Golem::Component>(std::make_shared<Golem::CameraScript>());
    n.lock()->addComponent(cameraCompo);
}

void GameWindow::render(){
/*
    ImGui::Begin("Hello, world!");
    if (ImGui::Button("Button"))
    {
    //... my_code
    }
    ImGui::End();*/
}
