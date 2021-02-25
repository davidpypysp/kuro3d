#ifndef SRC_CORE_SCENE_NODE_BASE_H_
#define SRC_CORE_SCENE_NODE_BASE_H_

#include <string>
#include <vector>
#include <memory>

namespace kuro {

class NodeBase : public std::enable_shared_from_this<NodeBase> {
 public:
  NodeBase();
  explicit NodeBase(const std::string& name);
  virtual ~NodeBase();

  void AddChild(std::shared_ptr<NodeBase> node);
  void RemoveChild(std::shared_ptr<NodeBase> node);
  void set_parent(std::shared_ptr<NodeBase> parent) { this->parent_ = parent; }

  std::vector<std::shared_ptr<NodeBase>>& child_nodes() { return child_nodes_; }

 protected:
  std::string name_;
  std::vector<std::shared_ptr<NodeBase>> child_nodes_;
  std::shared_ptr<NodeBase> parent_;
};

}  // namespace kuro

#endif  // SRC_CORE_SCENE_NODE_BASE_H_
