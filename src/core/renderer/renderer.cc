#include "src/core/renderer/renderer.h"

#include "src/core/base/visual_comp.h"

namespace kuro {

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() {}

void Renderer::RenderScene(std::shared_ptr<SceneManager> scene_manager) {
  // Turn all visual component into render data
  TransferSceneNodeData(scene_manager->root_node());
}

void Renderer::TransferSceneNodeData(std::shared_ptr<SceneNode> scene_node) {
  // TODO: what's this line
  scene_node->UpdateTransforms();

  for (auto component : scene_node->GetComponents()) {
    if (auto visual_pack = std::dynamic_pointer_cast<VisualComp>(component)) {
      // visual comp pass data to pipeline
      visual_pack->Render();
    }
  }

  // recursively pass child nodes
  for (auto child_node : scene_node->child_nodes()) {
    TransferSceneNodeData(child_node);
  }
}

}  // namespace kuro
