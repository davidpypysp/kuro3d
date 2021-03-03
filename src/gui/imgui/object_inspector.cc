#include <glm/gtc/type_ptr.hpp>
#include "src/gui/imgui/object_inspector.h"
#include "src/gui/imgui/gui.h"

namespace kuro {

namespace gui {

ObjectInspector::ObjectInspector(const std::string &name) : Window(name) {}

void ObjectInspector::Render() {
  auto scene_node = Gui::Instance()->selected_scene_node();
  if (!scene_node) {
    return;
  }

  char *name = const_cast<char *>(scene_node->name().c_str());
  ImGui::InputText("Name", name, 200);
  ImGui::SliderFloat3("Position", scene_node->PositionPtr(), -10.0, 10.0);
  ImGui::SliderFloat3("Rotation", scene_node->RotationPtr(), -10.0, 10.0);
  ImGui::SliderFloat3("Scale", scene_node->ScalePtr(), 0.1, 2.0);

  ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
              1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}

}  // namespace gui

}  // namespace kuro