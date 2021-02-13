#ifndef KURO_GUI_IMGUI_GUI_H_
#define KURO_GUI_IMGUI_GUI_H_

#include <glad/glad.h>  // Initialize with gladLoadGL()
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace kuro {

class Gui {
 public:
  Gui();
  int Init();
  void PrepareDraw();
  void Draw();
  void Cleanup();

  GLFWwindow* window() { return window_; }

  GLFWwindow* window_;

 private:
  bool show_demo_window_ = true;
  bool show_another_window_ = false;
  ImVec4 clear_color_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

}  // namespace kuro

#endif  // KURO_GUI_IMGUI_GUI_H_