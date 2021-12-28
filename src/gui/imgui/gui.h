#ifndef GUI_IMGUI_GUI_H_
#define GUI_IMGUI_GUI_H_

#include <string>
#include <memory>

#include "src/gui/imgui/gui_base.h"
#include "src/gui/imgui/scene_explorer.h"
#include "src/gui/imgui/object_inspector.h"

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

  void set_selected_scene_node(std::shared_ptr<SceneNode> scene_node) {
    selected_scene_node_ = scene_node;
  }
  std::shared_ptr<SceneNode> selected_scene_node() {
    return selected_scene_node_;
  }

 protected:
  static Gui* instance_;

  void InitWindows();

  std::shared_ptr<SceneExplorer> scene_explorer_;
  std::shared_ptr<ObjectInspector> object_inspector_;

  std::shared_ptr<SceneNode> selected_scene_node_;
};

}  // namespace gui

}  // namespace kuro

#endif  // GUI_IMGUI_GUI_H_
