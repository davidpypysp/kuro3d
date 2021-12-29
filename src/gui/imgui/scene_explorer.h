#ifndef GUI_IMGUI_SCENE_EXPLORER_H_
#define GUI_IMGUI_SCENE_EXPLORER_H_

#include <string>
#include "src/gui/imgui/window.h"
#include "src/core/engine.h"

namespace kuro {
namespace gui {

class SceneExplorer : public Window {
 public:
  explicit SceneExplorer(const std::string &name);

  void Render();

 protected:
  static bool TreeNode(std::shared_ptr<SceneNode> scene_node,
                       ImGuiTreeNodeFlags flags = 0);

  void RenderNodes(std::shared_ptr<SceneNode> scene_node);
  static const ImGuiTreeNodeFlags base_flags_ =
      ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_DefaultOpen;
};

}  // namespace gui
}  // namespace kuro

#endif  // GUI_IMGUI_SCENE_EXPLORER_H_
