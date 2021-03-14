#include "src/core/renderer/renderer.h"
#include "src/core/engine.h"
#include "src/core/elements/visual_pack.h"

namespace kuro {

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() {
  shader_ =
      std::make_shared<Shader>("model_loading.vert", "model_loading.frag");
}

void Renderer::DrawScene() {
  auto scene_manager = Engine::GetSceneManager();
  auto camera = scene_manager->current_camera();

  shader_->Use();
  shader_->SetMat4("projection", camera->GetPerspectiveMatrix());
  shader_->SetMat4("view", camera->GetViewMatrix());

  DrawSceneNodeTree(scene_manager->root_node());
}

void Renderer::DrawSceneNodeTree(std::shared_ptr<SceneNode> scene_node) {
  DrawSceneNode(scene_node);
  for (auto child_node : scene_node->child_nodes()) {
    DrawSceneNodeTree(child_node);
  }
}

void Renderer::DrawSceneNode(std::shared_ptr<SceneNode> scene_node) {
  for (auto pack : scene_node->GetPacks()) {
    if (auto visual_pack = std::dynamic_pointer_cast<VisualPack>(pack)) {
      scene_node->UpdateLocalTransform();
      shader_->SetMat4("model", scene_node->LocalTransform());
      visual_pack->Draw(*shader_);
    }
  }
}

}  // namespace kuro
