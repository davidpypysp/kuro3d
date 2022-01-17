#include "src/core/scene/scene_manager.h"

namespace kuro {

SceneManager::SceneManager() { root_node_ = CreateSceneNode("root_node"); }

}  // namespace kuro
