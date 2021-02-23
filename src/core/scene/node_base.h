#ifndef KURO_CORE_SCENE_NODE_BASE_H_
#define KURO_CORE_SCENE_NODE_BASE_H_

#include <vector>
#include <memory>

namespace kuro {

class NodeBase : std::enable_shared_from_this<NodeBase> {
 public:
  NodeBase();
  NodeBase(const std::string& name);

  std::shared_ptr<NodeBase> CreateChild(const std::string& name);
  void AddChild(std::shared_ptr<NodeBase> node);
  void RemoveChild(std::shared_ptr<NodeBase> node);
  void set_parent(std::shared_ptr<NodeBase> parent) { this->parent_ = parent; }

 protected:
  std::string name_;
  std::vector<std::shared_ptr<NodeBase>> child_nodes_;
  std::shared_ptr<NodeBase> parent_;
};

}  // namespace kuro

#endif  // KURO_CORE_SCENE_NODE_BASE_H_