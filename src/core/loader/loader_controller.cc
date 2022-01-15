#include "src/core/loader/loader_controller.h"

#include "src/core/loader/model_loader.h"

namespace kuro {

LoaderController::LoaderController() {
  auto model_loader = Register<ModelLoader>();
}

}  // namespace kuro
