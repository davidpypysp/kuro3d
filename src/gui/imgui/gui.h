#ifndef SRC_GUI_IMGUI_GUI_H_
#define SRC_GUI_IMGUI_GUI_H_

#include <string>
#include <memory>

#include "src/gui/imgui/gui_base.h"
#include "src/gui/imgui/scene_explorer.h"

namespace kuro {

namespace gui {

class Gui : public GuiBase {
 public:
  Gui(GLFWwindow* window, const char* glsl_version);

  static void Init(GLFWwindow* window, const char* glsl_version);
  static Gui* Instance();

  template <class T>
  static std::shared_ptr<T> CreateWindow(const std::string& name) {
    return instance_->AddWindow<T>(name);
  }

 protected:
  static Gui* instance_;

  void InitWindows();

  std::shared_ptr<SceneExplorer> scene_explorer_;
};

}  // namespace gui

}  // namespace kuro

#endif  // SRC_GUI_IMGUI_GUI_H_
