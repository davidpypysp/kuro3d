#include "src/core/scene/scene_manager.h"
#include "src/core/elements/model_pack.h"
#include "src/core/atoms/camera_atom.h"

namespace kuro {

SceneManager::SceneManager() {}

void SceneManager::CreateDefaultScene() {
  this->root_node_ = std::make_shared<SceneNode>("root");
  AddSceneNode(this->root_node_);

  // default camera
  current_camera_ = CameraAtom::Create("default_camera");
  AddSceneNode(current_camera_);
  current_camera_->set_position(glm::vec3(0, 0, 3));

  // example model
  auto model_pack =
      std::make_shared<ModelPack>("resources/backpack/backpack.obj");
  auto example_node = std::make_shared<SceneNode>("example_model");
  example_node->BindPack(model_pack);
  this->root_node_->AddChildSceneNode(example_node);
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

// template <class T>
// std::shared_ptr<T> SceneManager::CreateSceneNode(const std::string &name) {
//   std::shared_ptr<SceneNode> t = std::make_shared<T>(name);
//   return std::static_pointer_cast<T>(t);
// }

}  // namespace kuro
