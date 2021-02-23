#include "src/core/scene/node_base.h"

namespace kuro {

NodeBase::NodeBase() {}

NodeBase::NodeBase(const std::string& name) : name_(name) {}

std::shared_ptr<NodeBase> NodeBase::CreateChild(const std::string& name) {
  auto node = std::make_shared<NodeBase>(name);
  AddChild(node);
  return node;
}

void NodeBase::AddChild(std::shared_ptr<NodeBase> node) {
  node->set_parent(shared_from_this());
  child_nodes_.push_back(node);
}

void NodeBase::RemoveChild(std::shared_ptr<NodeBase> node) {}

}  // namespace kuro