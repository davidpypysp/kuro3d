#include "src/core/scene/scene_node.h"

namespace kuro {

SceneNode::SceneNode() {}

std::shared_ptr<SceneNode> SceneNode::AddChildNode() {
  auto node = std::make_shared<SceneNode>();
  scene_nodes_.push_back(node);
  return node;
}

}  // namespace kuro