#include "src/core/scene/scene_node.h"
#include "src/core/scene/scene_manager.h"
#include "src/core/elements/pack.h"

namespace kuro {

SceneNode::SceneNode(const std::string& name) : NodeBase(name) {}

void SceneNode::BindPack(std::shared_ptr<Pack> pack) {
  this->packs_.push_back(pack);
  pack->set_scene_node(shared_from_this());
}

void SceneNode::UnbindPack(std::shared_ptr<Pack> pack) {}

PackList& SceneNode::GetPacks() { return packs_; }

void SceneNode::AddChildSceneNode(std::shared_ptr<SceneNode> scene_node) {
  AddChild(scene_node);
  scene_manager_->AddSceneNode(scene_node);
}

}  // namespace kuro
