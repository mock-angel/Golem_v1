/*
 * ImGuiGame.cpp
 *
 *  Created on: 06-Dec-2020
 *      Author: anantha
 */

#include "ImGuiScene.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"
#include "Debug.h"
#include "Graphics/Camera/CameraManager.h"
#include "Core/Event/Event.h"
#include "Core/Input/InputSystem.h"
#include "Core/Input/Input.h"
#include "EditorCameraScript.h"
#include "Node.h"

namespace Golem {

ImGuiScene::ImGuiScene() {
    // TODO Auto-generated constructor stub
    //frameBuffer.create(720, 720);
    //frameBuffer.bind();
    //frameBuffer.unbind();
    //m_editorCamera = CameraManager::CreateEditorCamera();

    Quaternion q;
    Vector3 v = Vector3(0, 0, -3);
    auto editorCameraNode = Node::Instantiate(v, q);

    std::shared_ptr<ComponentOld> editorCamCompo = Golem::ComponentTypeHolder::getComponent("EditorCameraScript")->createNewShared();
    editorCameraNode.lock()->addComponent(editorCamCompo);
    //editorCameraNode.lock()->getComponent<EditorCameraSystem>();

    std::shared_ptr<EditorCameraScript> camCompo = std::dynamic_pointer_cast<EditorCameraScript>(editorCamCompo);
    m_editorCamera = camCompo->getCamera();
}

ImGuiScene::~ImGuiScene() {
    // TODO Auto-generated destructor stub
}


void ImGuiScene::update(){

    static ImVec2 windowRegion;
    bool isFocused;

    ImGui::Begin("Scene");
    isFocused = ImGui::IsWindowFocused();

    ImGui::BeginChild("GameRender");
    if(!isFocused) isFocused = ImGui::IsWindowFocused();
    ImVec2 wsize = ImGui::GetWindowSize();//TODO: GetContentRegionAvail or GetWindowSize?

    // Resize framebuffer when required.
    // TODO: Resize after sending texture to image?
    if(regionAvailX != wsize.x || regionAvailY != wsize.y){
        m_editorCamera->setWidth(wsize.x);
        m_editorCamera->setHeight(wsize.y);
        m_editorCamera->resizeTextures();
        regionAvailX = wsize.x;
        regionAvailY = wsize.y;
    }




    if(isFocused){
        bool isBeyongWindow = false;

        ImVec2 MousePos = ImGui::GetMousePos();
        ImVec2 MouseRelativePos(MousePos.x - ImGui::GetCursorScreenPos().x, MousePos.y - ImGui::GetCursorScreenPos().y) ;

        if(MouseRelativePos.x <= 0 || MouseRelativePos.y <= 0) isBeyongWindow = true;

        if(!isBeyongWindow){
            //if(Input::GetModButton(KMOD_LSHIFT)) Debug::log("Lshift worked! ");
            //if(Input::GetModButton(KMOD_LCTRL)) Debug::log("Lctrl worked! ");
        }

        //Debug::log("scene mouse.xy :", std::to_string(MousePos.x - ImGui::GetCursorScreenPos().x - ImGui::GetScrollX()) + ", " + std::to_string(MousePos.y - ImGui::GetCursorScreenPos().y - ImGui::GetScrollY()));
        //Debug::log("scene mouse.xy :", std::to_string(MousePos.x - ImGui::GetCursorScreenPos().x ) + ", " + std::to_string(MousePos.y - ImGui::GetCursorScreenPos().y ));
    }

    ImGui::Image((ImTextureID) m_editorCamera->getTargetTexture().get(), wsize, ImVec2(0, 1), ImVec2(1, 0));  // Need to invert the V from the UV.

    ImGui::EndChild();

    ImGui::End();

}

void ImGuiScene::OnEvent(Event& event){
    //Debug::log("GOt Event!!!!");

    InputEventListener::OnEvent(event);
}


void ImGuiScene::OnKeyDown(KeyPressedEvent& event)
{
    //Debug::log("KeyPressedEvent");
}
void ImGuiScene::OnKeyUp(KeyReleasedEvent& event)
{
    //Debug::log("OnKeyUp");
}
void ImGuiScene::OnMouseMove(MouseMotionEvent& event)
{

    //Debug::log("OnMouseMove");
}
void ImGuiScene::OnMouseButtonDown(MouseButtonEventDown& event)
{
   // Debug::log("OnMouseButtonUp");
}
void ImGuiScene::OnMouseButtonUp(MouseButtonEventUp& event)
{
    //Debug::log("OnMouseButtonUp");
}
void ImGuiScene::OnMouseWheel(MouseWheelEvent& event)
{
    //Debug::log("OnMouseWheel");
}


} /* namespace Golem */
