#include "src/gui/imgui/gui.h"

#include <iostream>

namespace kuro {

namespace gui {

Gui* Gui::instance_ = nullptr;

Gui::Gui(GLFWwindow* window, const char* glsl_version)
    : GuiBase(window, glsl_version) {}

void Gui::Init(GLFWwindow* window, const char* glsl_version) {
  instance_ = new Gui(window, glsl_version);
  instance_->InitWindows();
}

Gui* Gui::Instance() { return instance_; }

void Gui::InitWindows() {
  scene_explorer_ = AddWindow<SceneExplorer>("scene_explorer");
}

}  // namespace gui

}  // namespace kuro
