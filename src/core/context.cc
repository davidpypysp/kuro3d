#include "src/core/context.h"

#include "src/core/scene/scene_controller.h"
#include "src/core/loader/loader_controller.h"
#include "src/core/renderer/renderer_controller.h"

#include "src/core/loader/model_loader.h"
#include "src/core/io/rect_window.h"
#include "src/core/renderer/renderer.h"

namespace kuro {

Context::Context() {
  auto scene_controller = Register<SceneController>();
  auto renderer_controller = Register<RendererController>();
  auto loader_controller = Register<LoaderController>();

  // resolve cross dependencies
  auto texture_loader = loader_controller->Resolve<TextureLoader>();
  auto model_loader = loader_controller->Resolve<ModelLoader>();
  auto render_api = renderer_controller->Resolve<RenderAPI>();
  auto scene_manager = scene_controller->Resolve<SceneManager>();
  auto renderer = renderer_controller->Resolve<Renderer>();

  texture_loader->RegisterRenderAPI(render_api);
  model_loader->RegisterRenderAPI(render_api);
  renderer->RegisterSceneManager(scene_manager);

  Register<RectWindow>();

  Register<ModelLoader>(model_loader);
  Register<SceneManager>(scene_manager);
  Register<RenderAPI>(render_api);
  Register<Renderer>(renderer);
}

}  // namespace kuro