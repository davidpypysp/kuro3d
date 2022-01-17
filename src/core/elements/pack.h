#ifndef CORE_ELEMENTS_PACK_H_
#define CORE_ELEMENTS_PACK_H_

#include <memory>
#include "src/core/scene/scene_node.h"

namespace kuro {
namespace core {

class SceneNode;

// the basic unit of all elements
class Pack {
 public:
  Pack();
  virtual ~Pack();

  void set_scene_node(std::shared_ptr<SceneNode> scene_node) {
    scene_node_ = scene_node;
  }

 protected:
  std::shared_ptr<SceneNode> scene_node_;
};

} /* namespace core */
}  //  namespace kuro

#endif  // CORE_ELEMENTS_BASE_PACK_H_
