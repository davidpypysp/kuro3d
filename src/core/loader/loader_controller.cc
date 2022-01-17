#include "src/core/loader/loader_controller.h"

#include "src/core/loader/model_loader.h"
#include "src/core/loader/texture_loader.h"

namespace kuro {

LoaderController::LoaderController() {
  auto model_loader = Register<ModelLoader>();

  auto texture_loader = Register<TextureLoader>();
  model_loader->RegisterTextureLoader(texture_loader);
}

}  // namespace kuro
