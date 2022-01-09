#include "src/gui/imgui/gui_manager.h"

#include <iostream>

namespace kuro {

namespace gui {

GuiManager::GuiManager() : GuiBase() {}

void GuiManager::Init() { InitWindows(); }

void GuiManager::InitWindows() {
  scene_explorer_ = AddWindow<SceneExplorer>("Scene Explorer");

  object_inspector_ = AddWindow<ObjectInspector>("Object Inspector");
}

}  // namespace gui

}  // namespace kuro
