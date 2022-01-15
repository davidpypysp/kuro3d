#include "src/core/context.h"

#include "src/core/scene/scene_controller.h"
#include "src/core/loader/loader_controller.h"
#include "src/core/renderer/renderer_controller.h"
#include "src/core/io/rect_window.h"

namespace kuro {

Context::Context() {
  auto scene_controller = Register<SceneController>();
  auto loader_controller = Register<LoaderController>();
  auto renderer_controller = Register<RendererController>();

  Register<RectWindow>();

  Register<SceneManager>(scene_controller->Resolve<SceneManager>());
  Register<ModelLoader>(loader_controller->Resolve<ModelLoader>());
  Register<RenderAPI>(renderer_controller->Resolve<RenderAPI>());
}

}  // namespace kuro