#include "src/core/renderer/renderer_controller.h"

#include "src/core/renderer/rendering_pipeline.h"
#include "src/core/renderer/shader_manager.h"
#include "src/core/renderer/render_api.h"
#include "src/core/renderer/renderer.h"

namespace kuro {

RendererController::RendererController() { ResolveDependencies(); }

void RendererController::ResolveDependencies() {
  auto shader_manager = Register<ShaderManager>();

  auto render_api = Register<RenderAPI>();

  auto rendering_pipeline = Register<RenderingPipeline>();
  rendering_pipeline->Register<RendererAPI>(render_api);
  rendering_pipeline->Register<ShaderManager>(shader_manager);

  auto renderer = Register<Renderer>();
  renderer->Register<RenderingPipeline>(rendering_pipeline);
}

}  // namespace kuro