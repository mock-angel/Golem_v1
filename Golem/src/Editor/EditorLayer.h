/*
 * EditorLayer.h
 *
 *  Created on: 03-Dec-2020
 *      Author: anantha
 */

#ifndef EDITOR_EDITORLAYER_H_
#define EDITOR_EDITORLAYER_H_

#include <memory>

#include "Core/GUI/ImGuiWindow.h"

namespace Golem {

class ImGuiResourceManager;
class GuiNodeHeirarchy;
class GUIEditorNodeInspector;

class DebugGUI;
class ImGuiGame;
class ImGuiScene;

class EditorLayer: public ImGuiWindow {
public:
    EditorLayer();
    ~EditorLayer();

    void update();

private:
    std::shared_ptr<ImGuiResourceManager> m_resourceManagerGUI;
    std::shared_ptr<GuiNodeHeirarchy> m_heirarchyGUI;
    std::shared_ptr<GUIEditorNodeInspector> m_nodeInspectorGUI;

    std::shared_ptr<DebugGUI> m_editorDebugGUI;
    std::shared_ptr<ImGuiGame> m_editorGameWindowGUI;
    std::shared_ptr<ImGuiScene> m_editorSceneWindowGUI;

    void SetDarkThemeColors();

    bool m_isOpen = true;
};

} /* namespace Golem */

#endif /* EDITOR_EDITORLAYER_H_ */
