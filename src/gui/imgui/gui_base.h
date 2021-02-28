#ifndef SRC_GUI_IMGUI_GUI_BASE_H_
#define SRC_GUI_IMGUI_GUI_BASE_H_

#include <string>
#include <memory>
#include <vector>
#include <glad/glad.h>  // Initialize with gladLoadGL()
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "src/gui/imgui/window.h"

namespace kuro {

namespace gui {

class GuiBase {
 public:
  GuiBase(GLFWwindow* window, const char* glsl_version);
  ~GuiBase();
  void Draw();

 protected:
  template <class T>
  std::shared_ptr<T> AddWindow(const std::string& name) {
    std::shared_ptr<Window> window = std::make_shared<T>(name);
    windows_.push_back(window);
    return std::static_pointer_cast<T>(window);
  }

  GLFWwindow* window_;
  std::vector<std::shared_ptr<Window>> windows_;
};

}  // namespace gui

}  // namespace kuro

#endif  // SRC_GUI_IMGUI_GUI_BASE_H_
