#include "src/core/renderer/renderer.h"

namespace kuro {

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::Init() { rendering_pipeline_->Setup(); }

void Renderer::RenderScene() {
  rendering_pipeline_->DrawFrame(scene_manager_->root_node(),
                                 scene_manager_->camera_node());
}

}  // namespace kuro
