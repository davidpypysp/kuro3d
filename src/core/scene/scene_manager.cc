#include "src/core/scene/scene_manager.h"
#include "src/core/elements/model_pack.h"
#include "src/core/elements/camera_atom.h"

namespace kuro {

SceneManager::SceneManager() {}

void SceneManager::CreateDefaultScene() {
  this->root_node_ = CreateSceneNode<SceneNode>("root");

  // default camera
  current_camera_ = CreateSceneNode<CameraAtom>("default_camera", root_node_,
                                                glm::vec3(0, 0, 8));

  // example model
  auto example_node = CreateSceneNode<SceneNode>("example_model", root_node_);
  auto model_pack =
      std::make_shared<ModelPack>("resources/backpack/backpack.obj");
  example_node->BindPack(model_pack);
}

void SceneManager::Draw(std::shared_ptr<Shader> shader) {
  shader->Use();
  DrawNodeTree(this->root_node_, shader);
}

void SceneManager::DrawNodeTree(std::shared_ptr<SceneNode> scene_node,
                                std::shared_ptr<Shader> shader) {
  current_camera_->DrawSceneNode(*scene_node, *shader);
  for (auto child_node : scene_node->child_nodes()) {
    DrawNodeTree(child_node, shader);
  }
}

void SceneManager::AddSceneNode(std::shared_ptr<SceneNode> scene_node) {
  scene_node->set_scene_manager(shared_from_this());
}

}  // namespace kuro
