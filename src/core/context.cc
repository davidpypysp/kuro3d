#include "src/core/context.h"

#include "src/core/scene/scene_controller.h"
#include "src/core/loader/loader_controller.h"
#include "src/core/renderer/renderer_controller.h"

namespace kuro {

Context::Context() {
  auto scene_controller = Register<SceneController>();
  auto loader_controller = Register<LoaderController>();
  auto renderer_controller = Register<RendererController>();

  // resolve cross dependencies
  auto scene_manager = scene_controller->Resolve<SceneManager>();
  auto model_loader = loader_controller->Resolve<ModelLoader>();
  model_loader->RegisterSceneManager(scene_manager);
}

}  // namespace kuro