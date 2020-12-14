/*
 * Input.cpp
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#include "Input.h"

namespace Golem {

bool Input::mouseButtonState[3] = {0, 0, 0};
bool Input::mouseButtonStateDown[3] = {0, 0, 0};
int Input::mouseScrollDirectionY;

std::set<SDL_Keycode> Input::keyboardButton;
std::set<SDL_Keycode> Input::keyboardButtonDown;
std::set<Uint16> Input::modKey;
std::set<Uint16> Input::modKeyDown;
Uint16 Input::modKeyTrial;
Uint16 Input::modKeyDownTrial;

bool Input::GetButton(SDL_Keycode keyCode)                // returns true only on the first frame during which the mouse button is clicked.
{
    if (keyboardButton.find(keyCode) != keyboardButton.end()) return true;
    else return false;
}
bool Input::GetButtonDown(SDL_Keycode keyCode)                // returns true only on the first frame during which the mouse button is clicked.
{
    if (keyboardButtonDown.find(keyCode) != keyboardButtonDown.end()) return true;
    else return false;
}
bool Input::GetModButton(Uint16 key)                // returns true only on the first frame during which the mouse button is clicked.
{
    return (modKeyTrial & key)? true: false;

    //if (modKey.find(key) != modKey.end()) return true;
    //else return false;
}
bool Input::GetModButtonDown(Uint16 key)                // returns true only on the first frame during which the mouse button is clicked.
{
    //if(modKeyDownTrial & key) return true;
    //else return false;

    return (modKeyDownTrial & key)? true: false;

    //if (modKeyDown.find(key) != modKeyDown.end()) return true;
    //else return false;
}
bool Input::GetMouseButton(int key)                    // returns true if mouse button is being pressed.
{
    if(key<0 || key>=3) return false;
    else return mouseButtonState[key];
}
bool Input::GetMouseButtonDown(int key)                // returns true only on the first frame during which the mouse button is clicked.
{
    if(key<0 || key>=3) return false;
    else return mouseButtonStateDown[key];
}

int Input::GetMouseScrollY(){
    return mouseScrollDirectionY;
}

} /* namespace Golem */
