#ifndef SRC_CORE_SCENE_SCENE_NODE_H_
#define SRC_CORE_SCENE_SCENE_NODE_H_

#include <glad/glad.h>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "src/utils/node_base.h"

namespace kuro {

class SceneManager;
class Pack;

typedef std::vector<std::shared_ptr<Pack>> PackList;

class SceneNode : public NodeBase<SceneNode> {
 public:
  SceneNode(const std::string& name);

  static std::shared_ptr<SceneNode> Create(const std::string& name);

  void BindPack(std::shared_ptr<Pack> pack);
  void UnbindPack(std::shared_ptr<Pack> pack);
  PackList& GetPacks();

  void AddChildSceneNode(std::shared_ptr<SceneNode> scene_node);

  void set_id(const uint32_t id) { id_ = id; }

  glm::vec3 position() const { return position_; }
  void set_position(const glm::vec3& position) { position_ = position; }

  glm::vec3 rotation() { return rotation_; }
  void set_rotation(const glm::vec3& rotation) { rotation_ = rotation; }

  glm::vec3 scale() { return scale_; }
  void set_scale(const glm::vec3& scale) { scale_ = scale; }

  float* PositionPtr();
  float* RotationPtr();
  float* ScalePtr();

  std::shared_ptr<SceneManager> scene_manager() { return scene_manager_; }
  void set_scene_manager(std::shared_ptr<SceneManager> scene_manager) {
    scene_manager_ = scene_manager;
  }

 protected:
  uint32_t id_;

  // transformation
  glm::vec3 position_;
  glm::vec3 rotation_;
  glm::vec3 scale_ = {1.0, 1.0, 1.0};

  std::shared_ptr<SceneManager> scene_manager_;

  // children
  PackList packs_;
};

}  // namespace kuro

#endif  // SRC_CORE_SCENE_SCENE_NODE_H_
