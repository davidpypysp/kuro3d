#include <glm/gtx/string_cast.hpp>

#include "src/core/scene/camera_node.h"
#include "src/core/elements/visual_pack.h"

namespace kuro {

CameraNode::CameraNode(const std::string& name) : SceneNode(name) {
  std::shared_ptr<CameraPack> camera_pack = std::make_shared<CameraPack>();
  BindPack(camera_pack);
  camera_pack_ = camera_pack;
}

void CameraNode::DrawSceneNode(const std::shared_ptr<SceneNode> scene_node,
                               const std::shared_ptr<Shader> shader) {
  if (scene_node->GetPacks().size() == 0) {
    return;
  }
  const float kRatio = 2;
  glm::mat4 projection = camera_pack_->GetPerspectiveMatrix(kRatio);
  glm::mat4 view = camera_pack_->GetViewMatrix(position_);

  shader->SetMat4("projection", projection);
  shader->SetMat4("view", view);

  for (auto pack : scene_node->GetPacks()) {
    if (auto visual_pack = std::dynamic_pointer_cast<VisualPack>(pack)) {
      glm::mat4 model = glm::mat4(1.0);
      model = glm::translate(model, scene_node->position());
      // model = glm::scale(model, scene_node->scale());
      shader->SetMat4("model", model);
      visual_pack->Draw(*shader);
    }
  }
}

}  // namespace kuro
