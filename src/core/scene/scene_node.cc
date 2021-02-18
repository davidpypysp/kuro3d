#include "src/core/scene/scene_node.h"

namespace kuro {

SceneNode::SceneNode() {}

std::shared_ptr<SceneNode> SceneNode::AddChildNode() {
  auto scene_node = std::make_shared<SceneNode>();
  scene_nodes_.push_back(scene_node);
  return scene_node;
}

void SceneNode::AddChildNode(std::shared_ptr<SceneNode> scene_node) {
  scene_nodes_.push_back(scene_node);
}

}  // namespace kuro