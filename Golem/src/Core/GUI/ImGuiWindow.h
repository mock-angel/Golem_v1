/*
 * ImGuiWindow.h
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_GUI_IMGUIWINDOW_H_
#define CORE_GUI_IMGUIWINDOW_H_

namespace Golem {

class Event;

class ImGuiWindow {
public:
    ImGuiWindow();
    virtual ~ImGuiWindow();

    //bool isOpen();
    virtual void update(){}
    virtual void close(){ m_opened = false;}
    virtual void open(){ m_opened = true;}

    inline bool isOpen(){ return m_opened; }

    virtual void OnEvent(Event& event){ ; }
protected:
    bool m_opened = false;
};

} /* namespace Golem */

#endif /* CORE_GUI_IMGUIWINDOW_H_ */
