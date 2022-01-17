#include "src/core/scene/scene_controller.h"

#include "src/core/scene/scene_manager.h"

namespace kuro {

SceneController::SceneController() { Register<SceneManager>(); }

}  // namespace kuro