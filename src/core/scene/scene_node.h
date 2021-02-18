#ifndef KURO_CORE_SCENE_SCENE_NODE_H_
#define KURO_CORE_SCENE_SCENE_NODE_H_

#include "src/core/object/base_object.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <memory>

namespace kuro {

class SceneNode {
 public:
  SceneNode();
  std::shared_ptr<SceneNode> AddChildNode();
  void AddChildNode(std::shared_ptr<SceneNode> scene_node);

  void set_object(std::shared_ptr<BaseObject> object) { object_ = object; }
  std::shared_ptr<BaseObject> object() { return object_; }
  std::vector<std::shared_ptr<SceneNode>>& scene_nodes() {
    return scene_nodes_;
  }

  glm::vec3 position() const { return position_; }
  glm::vec3 rotation() const { return rotation_; }
  glm::vec3 scale() const { return scale_; }

 protected:
  std::string id_;
  std::string name_;
  glm::vec3 position_;
  glm::vec3 rotation_;
  glm::vec3 scale_;

  std::vector<std::shared_ptr<SceneNode>> scene_nodes_;

  std::shared_ptr<BaseObject> object_ = nullptr;
};

}  // namespace kuro

#endif  // KURO_CORE_SCENE_SCENE_NODE_H_