#include "src/core/scene/scene_manager.h"
#include "src/core/elements/model.h"

namespace kuro {

SceneManager::SceneManager() { root_node_ = std::make_shared<SceneNode>(); }

void SceneManager::InitDefaultScene() {
  auto default_camera = std::make_shared<Camera>(glm::vec3(0.0, 0.0, 3.0));
  root_node_->AddChildNode(default_camera);
  current_camera_ = default_camera;

  auto node = root_node_->AddChildNode();
  auto model = std::make_shared<Model>("resources/backpack/backpack.obj");
  node->set_object(model);
}

void SceneManager::Draw(std::shared_ptr<Shader> shader) {
  shader->Use();
  DrawNodeTree(root_node_, shader, current_camera_);
}

void SceneManager::DrawNodeTree(std::shared_ptr<SceneNode> scene_node,
                                std::shared_ptr<Shader> shader,
                                std::shared_ptr<Camera> camera) {
  DrawSceneNode(scene_node, shader, camera);
  for (const auto& child_node : scene_node->scene_nodes()) {
    DrawNodeTree(child_node, shader, camera);
  }
}

void SceneManager::DrawSceneNode(std::shared_ptr<SceneNode> scene_node,
                                 std::shared_ptr<Shader> shader,
                                 std::shared_ptr<Camera> camera) {
  if (!scene_node->object()) {
    return;
  }

  const float kRatio = 2;
  glm::mat4 projection = camera->GetPerspectiveMatrix(kRatio);
  glm::mat4 view = camera->GetViewMatrix();

  shader->SetMat4("projection", projection);
  shader->SetMat4("view", view);

  glm::mat4 model = glm::mat4(1.0);
  model = glm::translate(model, scene_node->position());
  // model = glm::scale(model, scene_node->scale());
  model = glm::scale(model, glm::vec3(1.0, 1.0, 1.0));
  shader->SetMat4("model", model);
  scene_node->object()->Draw(*shader);
}

}  // namespace kuro