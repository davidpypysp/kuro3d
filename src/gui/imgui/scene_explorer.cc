#include "src/gui/imgui/scene_explorer.h"
#include "src/gui/imgui/gui.h"

namespace kuro {
namespace gui {

SceneExplorer::SceneExplorer(const std::string &name) : Window(name) {}

bool SceneExplorer::TreeNode(std::shared_ptr<SceneNode> scene_node,
                             ImGuiTreeNodeFlags flags) {
  auto node_flags = base_flags_ | flags;
  if (scene_node == Gui::Instance()->selected_scene_node()) {
    node_flags |= ImGuiTreeNodeFlags_Selected;
  }
  bool node_open = ImGui::TreeNodeEx(scene_node.get(), node_flags,
                                     scene_node->name().c_str());
  if (ImGui::IsItemClicked()) {
    Gui::Instance()->set_selected_scene_node(scene_node);
    std::cout << "node " << scene_node->name() << " clicked" << std::endl;
  }
  return node_open;
}

void SceneExplorer::RenderNodes(std::shared_ptr<SceneNode> scene_node) {
  if (scene_node->child_nodes().size() == 0) {
    TreeNode(scene_node,
             ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen);
    return;
  }

  bool node_open = TreeNode(scene_node);
  if (node_open) {
    for (auto child_node : scene_node->child_nodes()) {
      RenderNodes(child_node);
    }
    ImGui::TreePop();
  }
}

void SceneExplorer::Render() {
  auto scene_manager = Engine::Instance()->scene_manager();
  RenderNodes(scene_manager->root_node());
}

}  // namespace gui

}  // namespace kuro
