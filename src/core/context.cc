#include "src/core/context.h"

#include "src/core/scene/scene_controller.h"
#include "src/core/loader/loader_controller.h"
#include "src/core/renderer/renderer_controller.h"

#include "src/core/loader/model_loader.h"
#include "src/core/io/rect_window.h"

namespace kuro {

Context::Context() {
  auto scene_controller = Register<SceneController>();
  auto renderer_controller = Register<RendererController>();
  auto loader_controller = Register<LoaderController>();

  // resolve cross dependencies
  auto texture_loader = loader_controller->Resolve<TextureLoader>();
  auto render_api = renderer_controller->Resolve<RenderAPI>();
  texture_loader->RegisterRenderAPI(render_api);

  Register<RectWindow>();

  Register<SceneManager>(scene_controller->Resolve<SceneManager>());
  Register<ModelLoader>(loader_controller->Resolve<ModelLoader>());
  Register<RenderAPI>(renderer_controller->Resolve<RenderAPI>());
}

}  // namespace kuro