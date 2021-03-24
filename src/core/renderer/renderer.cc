#include "src/core/renderer/renderer.h"
#include "src/core/engine.h"
#include "src/core/elements/visual_pack.h"

namespace kuro {

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() {
  shader_ = std::make_shared<Shader>("mesh_basic.vert", "mesh_basic.frag");
}

void Renderer::DrawScene() {
  auto scene_manager = Engine::GetSceneManager();
  auto camera = scene_manager->current_camera();

  shader_->Use();
  shader_->SetMat4("projection", camera->GetPerspectiveMatrix());
  shader_->SetMat4("view", camera->GetViewMatrix());

  DrawSceneNode(scene_manager->root_node());
}

void Renderer::DrawSceneNode(std::shared_ptr<SceneNode> scene_node) {
  scene_node->UpdateTransforms();
  shader_->SetMat4("model", scene_node->WorldTransform());
  for (auto pack : scene_node->GetPacks()) {
    if (auto visual_pack = std::dynamic_pointer_cast<VisualPack>(pack)) {
      visual_pack->Render();
    }
  }

  // recursively draw child nodes
  for (auto child_node : scene_node->child_nodes()) {
    DrawSceneNode(child_node);
  }
}

}  // namespace kuro
