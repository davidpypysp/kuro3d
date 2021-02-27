#ifndef SRC_GUI_IMGUI_GUI_H_
#define SRC_GUI_IMGUI_GUI_H_

#include <glad/glad.h>  // Initialize with gladLoadGL()
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace kuro {

class Gui {
 public:
  Gui(GLFWwindow* window, const char* glsl_version);
  static void Init(GLFWwindow* window, const char* glsl_version);
  static Gui* Instance();

  void Draw();
  void Cleanup();

 protected:
  static Gui* instance_;
  GLFWwindow* window_;

  bool show_demo_window_ = true;
  bool show_another_window_ = false;
  ImVec4 clear_color_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

}  // namespace kuro

#endif  // SRC_GUI_IMGUI_GUI_H_
