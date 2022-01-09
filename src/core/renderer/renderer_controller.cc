#include "src/core/renderer/renderer_controller.h"

#include "src/core/renderer/renderer.h"
#include "src/core/renderer/gl_render_api.h"

namespace kuro {

RendererController::RendererController() {
  auto shader_manager = Register<ShaderManager>();

  auto render_api = Register<RenderAPI, GLRenderAPI>();

  auto rendering_pipeline = Register<RenderingPipeline>();
  rendering_pipeline->RegisterRenderAPI(render_api);
  rendering_pipeline->RegisterShaderManager(shader_manager);

  auto renderer = Register<Renderer>();
  renderer->RegisterRenderingPipeline(rendering_pipeline);
}

}  // namespace kuro