#ifndef KURO_CORE_ELEMENTS_PACK_H_
#define KURO_CORE_ELEMENTS_PACK_H_

#include "src/core/renderer/shader.h"
#include "src/core/scene/scene_node.h"

namespace kuro {

// the basic unit of all elements
class Pack : public std::enable_shared_from_this<Pack> {
 public:
  Pack();

  void set_scene_node(std::shared_ptr<SceneNode> scene_node) {
    scene_node_ = scene_node;
  }

 protected:
  std::shared_ptr<SceneNode> scene_node_;
};

}  // namespace kuro

#endif  // KURO_CORE_ELEMENTS_BASE_PACK_H_