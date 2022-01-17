#include "src/core/context.h"

#include "src/core/scene/scene_manager.h"
#include "src/core/loader/model_loader.h"
#include "src/core/io/rect_window.h"
#include "src/core/renderer/renderer.h"
#include "src/core/renderer/gl_render_api.h"

namespace kuro {

Context::Context() {
  // Init Scene
  auto scene_manager = Register<SceneManager>();

  // Init Renderer
  auto shader_manager = Register<ShaderManager>();
  auto render_api = Register<RenderAPI, GLRenderAPI>();
  auto rendering_pipeline = Register<RenderingPipeline>();
  rendering_pipeline->RegisterRenderAPI(render_api);
  rendering_pipeline->RegisterShaderManager(shader_manager);
  auto renderer = Register<Renderer>();
  renderer->RegisterRenderingPipeline(rendering_pipeline);

  // Init Loader
  auto model_loader = Register<ModelLoader>();
  auto texture_loader = Register<TextureLoader>();
  model_loader->RegisterTextureLoader(texture_loader);

  // Init IO
  auto window = Register<RectWindow>();

  // resolve cross dependencies
  texture_loader->RegisterRenderAPI(render_api);
  model_loader->RegisterRenderAPI(render_api);
  renderer->RegisterSceneManager(scene_manager);
}

}  // namespace kuro