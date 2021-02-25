#ifndef SRC_GUI_IMGUI_GUI_MAIN_H_
#define SRC_GUI_IMGUI_GUI_MAIN_H_

#include "src/gui/imgui/gui.h"
#include "src/core/renderer/renderer.h"
#include <iostream>
#include <memory>

namespace kuro {

class GuiMain {
 public:
  GuiMain();
  int Run();
  void Init();
  void Loop();
  void Cleanup();

 private:
  std::unique_ptr<Gui> gui_;
  std::shared_ptr<Renderer> renderer_;
  GLFWwindow* window_;
};

}  // namespace kuro

#endif  // SRC_GUI_IMGUI_GUI_MAIN_H_