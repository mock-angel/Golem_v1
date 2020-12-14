/*
 * InputSystem.cpp
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#include "InputSystem.h"
#include "../../Game.h"
#include "Debug.h"
#include "Input.h"

namespace Golem {

InputSystem::InputSystem() {
    // TODO Auto-generated constructor stub
    //Event::typr
}

InputSystem::~InputSystem() {
    // TODO Auto-generated destructor stub
}

void InputSystem::handleRawInput(SDL_Event& e){

    if( e.type == SDL_WINDOWEVENT ){

        switch(e.window.event){
        case(SDL_WINDOWEVENT_SIZE_CHANGED):
            WindowResizedEvent windowResizedEvent(e.window.data1, e.window.data2);
            Game::getEventBus().lock()->Publish(windowResizedEvent);
            break;
            //Game::OnEvent(windowResizedEvent);
        }
    }

    if( e.type == SDL_MOUSEMOTION ){
        Debug::log("Mouse moved");
        MouseMotionEvent mouseMotionEvent(e.motion.x, e.motion.y);
        Game::getEventBus().lock()->Publish(mouseMotionEvent);
        //Game::OnEvent(windowResizedEvent);

    }
    if( e.type == SDL_MOUSEBUTTONDOWN ){

        MouseButtonEventDown mouseButtonEvent(e.button.button);
        Game::getEventBus().lock()->Publish(mouseButtonEvent);

        Input::mouseButtonState[e.button.button] = true;
        Input::mouseButtonStateDown[e.button.button] = true;
    }
    if( e.type == SDL_MOUSEBUTTONUP ){

        MouseButtonEventUp mouseButtonEvent(e.button.button);
        Game::getEventBus().lock()->Publish(mouseButtonEvent);

        Input::mouseButtonState[e.button.button] = false;
    }
    if( e.type == SDL_MOUSEWHEEL ){

        MouseWheelEvent mousewheelEvent(e.wheel.x, e.wheel.y);
        Game::getEventBus().lock()->Publish(mousewheelEvent);

        Input::mouseScrollDirectionY = e.wheel.y;
    }

    if( e.type == SDL_KEYDOWN ){
        //e.key.keysym.scancode
        //Debug::log(std::to_string(e.key.type));
        KeyPressedEvent keyEvent(e.key.keysym.sym, e.key.repeat);
        Game::getEventBus().lock()->Publish(keyEvent);

        Input::keyboardButton.emplace(e.key.keysym.sym);
        Input::keyboardButtonDown.emplace(e.key.keysym.sym);

        //if(e.key.keysym.mod != 4096) Input::modKeyTrial |= e.key.keysym.mod;

        Uint16 mod = e.key.keysym.mod;
        Input::modKeyTrial = e.key.keysym.mod;

        // https://www.libsdl.org/release/SDL-1.2.15/docs/html/guideinputkeyboard.html
        /* Check for the presence of each SDLMod value */
        /* This looks messy, but there really isn't    */
        /* a clearer way.                              */
        if( mod & KMOD_NUM ) printf( "NUMLOCK \n" );
        if( mod & KMOD_CAPS ) printf( "CAPSLOCK \n" );
        if( mod & KMOD_LCTRL ) printf( "LCTRL \n" );
        if( mod & KMOD_RCTRL ) printf( "RCTRL \n" );
        if( mod & KMOD_RSHIFT ) printf( "RSHIFT \n" );
        if( mod & KMOD_LSHIFT ) printf( "LSHIFT \n" );
        if( mod & KMOD_RALT ) printf( "RALT \n" );
        if( mod & KMOD_LALT ) printf( "LALT \n" );
        if( mod & KMOD_CTRL ) printf( "CTRL \n" );
        if( mod & KMOD_SHIFT ) printf( "SHIFT \n" );
        if( mod & KMOD_ALT ) printf( "ALT \n" );




    }
    if( e.type == SDL_KEYUP ){

        KeyReleasedEvent keyEvent(e.key.keysym.sym, e.key.repeat);
        Game::getEventBus().lock()->Publish(keyEvent);

        Uint16 mod = e.key.keysym.mod;
        Input::modKeyTrial = e.key.keysym.mod;

        Input::keyboardButton.erase(e.key.keysym.sym);
        Input::modKey.erase((e.key.keysym.mod));
    }

}

void InputSystem::prepare(){
    Input::mouseButtonStateDown[0] = Input::mouseButtonStateDown[1] = Input::mouseButtonStateDown[2] = false;
    Input::mouseScrollDirectionY = 0;
    Input::keyboardButtonDown.clear();
    Input::modKeyDown.clear();
    Input::modKeyDownTrial = 0;
}

} /* namespace Golem */
