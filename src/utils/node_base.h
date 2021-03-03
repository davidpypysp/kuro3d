#ifndef SRC_UTILS_NODE_BASE_H_
#define SRC_UTILS_NODE_BASE_H_

#include <string>
#include <vector>
#include <memory>

namespace kuro {

template <class T>
class NodeBase : public std::enable_shared_from_this<T> {
 public:
  explicit NodeBase(const std::string& name) : name_(name) {}
  virtual ~NodeBase() {}

  std::string name() const { return name_; }

  void AddChild(std::shared_ptr<T> node) { child_nodes_.push_back(node); }

  void RemoveChild(std::shared_ptr<T> node) {}

  void set_parent(std::shared_ptr<T> parent) { this->parent_ = parent; }

  std::vector<std::shared_ptr<T>>& child_nodes() { return child_nodes_; }

 protected:
  std::string name_;
  std::vector<std::shared_ptr<T>> child_nodes_;
  std::shared_ptr<T> parent_;
};

}  // namespace kuro

#endif  // SRC_UTILS_NODE_BASE_H_
