#include "src/core/scene/scene_node.h"

namespace kuro {

SceneNode::SceneNode() {}

SceneNode::SceneNode(const std::string name) : NodeBase(name) {}

void SceneNode::BindPack(std::shared_ptr<Pack> pack) {
  this->packs_.push_back(pack);
}

void SceneNode::UnbindPack(std::shared_ptr<Pack> pack) {}

PackList& SceneNode::GetPacks() { return packs_; }

template <class SN>
std::shared_ptr<SN> SceneNode::CreateChildSceneNode(const std::string& name) {
  assert(scene_manager_);

  auto child_node = this->scene_manager_->CreateSceneNode<SN>(name);
  child_node->set_parent(shared_from_this());
  return child_node;
}

}  // namespace kuro