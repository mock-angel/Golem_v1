/*
 * Input.h
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_INPUT_INPUT_H_
#define CORE_INPUT_INPUT_H_

#include "../Math/Vector2.h"

#include <string>
#include <set>

#include <SDL2/SDL_events.h>

namespace Golem {

class Input{

public:
    static Vector2 mousePosition;

    static int GetAxis(const std::string& axisName);        //Vertical/Horizontal

/***TODO
    static bool GetButton(const std::string& bName);        // returns true if key is being pressed.
    static bool GetButtonDown(const std::string& bName);    // returns true only on the first frame during which the keyis pressed.
***/
    static bool GetButton(SDL_Keycode keyCode);                     // returns true if key is being pressed.
    static bool GetButtonDown(SDL_Keycode keyCode);                 // returns true only on the first frame during which the keyis pressed.
    static bool GetModButton(Uint16 key);                // returns true only on the first frame during which the mouse button is clicked.
    static bool GetModButtonDown(Uint16 key);                // returns true only on the first frame during which the mouse button is clicked.
    static bool GetMouseButton(int key);                    // returns true if mouse button is being pressed.
    static bool GetMouseButtonDown(int key);                // returns true only on the first frame during which the mouse button is clicked.

    static int GetMouseScrollY();
private:
    friend class InputSystem;
    static bool mouseButtonState[3];
    static bool mouseButtonStateDown[3];
    static int mouseScrollDirectionY;

    static std::set<SDL_Keycode> keyboardButton;
    static std::set<SDL_Keycode> keyboardButtonDown;

    static std::set<Uint16> modKey;
    static std::set<Uint16> modKeyDown;
    static Uint16 modKeyTrial;
    static Uint16 modKeyDownTrial;

};

} /* namespace Golem */

#endif /* CORE_INPUT_INPUT_H_ */
