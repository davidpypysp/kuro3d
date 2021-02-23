#include "src/core/scene/scene_manager.h"
#include "src/core/elements/model.h"

namespace kuro {

SceneManager::SceneManager() { this->root_node = CreateSceneNode("root"); }

void SceneManager::CreateDefaultScene() {
  // default camera
  auto camera_node =
      this->root_node_->CreateChildSceneNode<CameraNode>("camera");
  this->current_camera_node_ = camera_node;

  // example model
  auto model_pack =
      std::make_shared<ModelPack>("resources/backpack/backpack.obj");
  auto example_node = this->root_node_->CreateChildSceneNode("example_model");
  example_node->BindPack(model_pack);
}

void SceneManager::Draw(std::shared_ptr<Shader> shader) {
  shader->Use();
  DrawNodeTree(this->root_node, shader, this->current_camera);
}

void SceneManager::DrawNodeTree(std::shared_ptr<SceneNode> scene_node,
                                std::shared_ptr<Shader> shader,
                                std::shared_ptr<Camera> camera) {
  DrawSceneNode(scene_node, shader, camera);
  for (const auto& child_node : scene_node->child_nodes) {
    DrawNodeTree(child_node, shader, camera);
  }
}

void SceneManager::DrawSceneNode(std::shared_ptr<SceneNode> scene_node,
                                 std::shared_ptr<Shader> shader,
                                 std::shared_ptr<Camera> camera) {
  if (!scene_node->atom) {
    return;
  }

  const float kRatio = 2;
  glm::mat4 projection = camera->GetPerspectiveMatrix(kRatio);
  glm::mat4 view = camera->GetViewMatrix();

  shader->SetMat4("projection", projection);
  shader->SetMat4("view", view);

  glm::mat4 model = glm::mat4(1.0);
  model = glm::translate(model, scene_node->position);
  // model = glm::scale(model, scene_node->scale());
  model = glm::scale(model, glm::vec3(1.0, 1.0, 1.0));
  shader->SetMat4("model", model);
  scene_node->atom->Draw(*shader);
}

template <class SN = SceneNode>
std::shared_ptr<SN> SceneManager::CreateSceneNode(const std::string& name) {
  std::shared_ptr<SceneNode> scene_node = std::make_shared<SN>(name);
  scene_node->set_scene_manager(shared_from_this());
  return static_cast<std::shared_ptr<SN>>(scene_node);
}

}  // namespace kuro