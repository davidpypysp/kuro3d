#include "src/gui/imgui/scene_explorer.h"

namespace kuro {
namespace gui {

SceneExplorer::SceneExplorer(const std::string &name) : Window(name) {}

void SceneExplorer::Render() {
  ImGui::SetNextItemOpen(true, ImGuiCond_Once);
  if (ImGui::TreeNode("Basic trees")) {
    for (int i = 0; i < 5; i++) {
      // Use SetNextItemOpen() so set the default state of a node to be open. We
      // could also use TreeNodeEx() with the ImGuiTreeNodeFlags_DefaultOpen
      // flag to achieve the same thing!
      ImGui::SetNextItemOpen(true, ImGuiCond_Once);

      if (ImGui::TreeNode((void *)(intptr_t)i, "Child %d", i)) {
        ImGui::Text("blah blah");
        ImGui::SameLine();
        if (ImGui::SmallButton("button")) {
        }
        ImGui::TreePop();
      }
    }
    ImGui::TreePop();
  }
}

}  // namespace gui

}  // namespace kuro
