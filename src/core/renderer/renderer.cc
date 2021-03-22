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

  DrawSceneNode(scene_manager->root_node(), mat4(1.0));
}

void Renderer::DrawSceneNode(std::shared_ptr<SceneNode> scene_node,
                             const mat4 &parent_transform) {
  scene_node->UpdateLocalTransform();
  mat4 world_transform = scene_node->LocalTransform() * parent_transform;
  shader_->SetMat4("model", world_transform);
  for (auto pack : scene_node->GetPacks()) {
    if (auto visual_pack = std::dynamic_pointer_cast<VisualPack>(pack)) {
      visual_pack->Draw(shader_);
    }
  }

  // recursively draw child nodes
  for (auto child_node : scene_node->child_nodes()) {
    DrawSceneNode(child_node, world_transform);
  }
}

}  // namespace kuro
