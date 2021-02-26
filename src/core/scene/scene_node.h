#ifndef SRC_CORE_SCENE_SCENE_NODE_H_
#define SRC_CORE_SCENE_SCENE_NODE_H_

#include <glad/glad.h>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "src/core/scene/node_base.h"

namespace kuro {

class SceneManager;
class Pack;

typedef std::vector<std::shared_ptr<Pack>> PackList;

class SceneNode : public NodeBase {
 public:
  explicit SceneNode(const std::string& name);

  void BindPack(std::shared_ptr<Pack> pack);
  void UnbindPack(std::shared_ptr<Pack> pack);
  PackList& GetPacks();

  void AddChildSceneNode(std::shared_ptr<SceneNode> scene_node);

  template <class T>
  std::shared_ptr<T> CreateChildNode(const std::string& name) {
    std::shared_ptr<SceneNode> node = std::make_shared<T>(name);
    AddChild(node);
    return std::static_pointer_cast<T>(node);
  }

  glm::vec3 position() const { return position_; }
  void set_position(const glm::vec3& position) { position_ = position; }

  glm::vec3 rotation() const { return rotation_; }
  void set_rotation(const glm::vec3& rotation) { rotation_ = rotation; }

  glm::vec3 scale() const { return scale_; }
  void set_scale(const glm::vec3& scale) { scale_ = scale; }

  void set_scene_manager(std::shared_ptr<SceneManager> scene_manager) {
    scene_manager_ = scene_manager;
  }

 protected:
  // transformation
  glm::vec3 position_;
  glm::vec3 rotation_;
  glm::vec3 scale_;

  std::shared_ptr<SceneManager> scene_manager_;

  // children
  PackList packs_;
};

}  // namespace kuro

#endif  // SRC_CORE_SCENE_SCENE_NODE_H_
