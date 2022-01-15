#include "src/gui/imgui/gui_manager.h"

#include <iostream>

namespace kuro {

namespace gui {

GuiManager::GuiManager() : GuiBase() {}

void GuiManager::Init() { InitWindows(); }

void GuiManager::InitWindows() {
  scene_explorer_ = AddWindow<SceneExplorer>("Scene Explorer");
  scene_explorer_->RegisterGuiStore(gui_store_);
  auto scene_manager = engine_->GetInstance<SceneManager>();
  scene_explorer_->RegisterSceneManager(scene_manager);

  object_inspector_ = AddWindow<ObjectInspector>("Object Inspector");
  object_inspector_->RegisterGuiStore(gui_store_);
}

}  // namespace gui

}  // namespace kuro
