#ifndef KURO_CORE_SCENE_SCENE_MANAGER_H_
#define KURO_CORE_SCENE_SCENE_MANAGER_H_

#include "src/core/scene/scene_node.h"

namespace kuro {

class SceneManager {
 public:
  SceneManager();

 private:
  void InitDefaultScene();

  SceneNode root_node_;
};

}  // namespace kuro

#endif  // KURO_CORE_SCENE_SCENE_MANAGER_H_