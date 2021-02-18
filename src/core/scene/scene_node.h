#ifndef KURO_CORE_SCENE_SCENE_NODE_H_
#define KURO_CORE_SCENE_SCENE_NODE_H_

#include "src/core/scene/scene_object.h"

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

 protected:
  std::shared_ptr<SceneNode> AddChildNode();

  std::string id_;
  std::string name_;
  glm::vec3 position_;
  glm::vec3 rotation_;
  glm::vec3 scale_;

  std::vector<std::shared_ptr<SceneNode>> scene_nodes_;

  std::shared_ptr<SceneObject> scene_object_;
};

}  // namespace kuro

#endif  // KURO_CORE_SCENE_SCENE_NODE_H_