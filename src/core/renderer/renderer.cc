#include "src/core/renderer/renderer.h"

namespace kuro {

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() {}

void Renderer::RenderScene() {
  pipeline_->DrawFrame(scene_manager_->root_node(),
                       scene_manager_->camera_node());
}

}  // namespace kuro
