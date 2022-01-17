#include "src/core/scene/scene_manager.h"

namespace kuro {
namespace core {

SceneManager::SceneManager() { root_node_ = CreateSceneNode("root_node"); }

} /* namespace core */
}  //  namespace kuro
