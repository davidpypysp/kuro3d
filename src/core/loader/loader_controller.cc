#include "src/core/loader/loader_controller.h"

namespace kuro {

LoaderController::LoaderController() {
  auto model_loader = Register<ModelLoader>();
}

}  // namespace kuro
