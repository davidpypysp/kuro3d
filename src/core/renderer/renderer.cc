#include "src/core/renderer/renderer.h"

namespace kuro {

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() {}

void Renderer::RenderScene(std::shared_ptr<SceneManager> scene_manager) {
  pipeline_->DrawFrame(scene_manager->root_node());
}

}  // namespace kuro
