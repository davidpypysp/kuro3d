#ifndef SRC_GUI_IMGUI_GUI_MAIN_H_
#define SRC_GUI_IMGUI_GUI_MAIN_H_

#include <iostream>
#include <memory>

#include "src/gui/imgui/gui.h"
#include "src/core/engine.h"

namespace kuro {

namespace gui {

class GuiMain {
 public:
  GuiMain();
  ~GuiMain();
  static GuiMain* Instance();

  int Run();
  void Loop();
  void Cleanup();

  static void FrameBufferSizeCallback(GLFWwindow* window, int width,
                                      int height);

 protected:
  static GuiMain* instance_;
  GLFWwindow* window_;
};

}  // namespace gui

}  // namespace kuro

#endif  // SRC_GUI_IMGUI_GUI_MAIN_H_
