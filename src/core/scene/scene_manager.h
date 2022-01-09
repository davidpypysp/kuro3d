#ifndef CORE_SCENE_SCENE_MANAGER_H_
#define CORE_SCENE_SCENE_MANAGER_H_

#include <memory>
#include <vector>
#include <string>

#include "src/core/scene/scene_node.h"
#include "src/utils/type_annotation.h"

namespace kuro {

typedef std::vector<std::shared_ptr<SceneNode>> SceneNodeList;

class SceneManager : public std::enable_shared_from_this<SceneManager> {
 public:
  SceneManager();

  std::shared_ptr<SceneNode> root_node() { return root_node_; }

  std::shared_ptr<SceneNode> CreateSceneNode(
      const std::string &name,
      const std::shared_ptr<SceneNode> parent = nullptr) {
    auto scene_node = std::make_shared<SceneNode>(name);
    scene_node->set_id(scene_node_id_max_++);
    if (parent) {
      parent->AddChildNode(scene_node);
    }
    return scene_node;
  }

  std::shared_ptr<SceneNode> CreateSceneNode(
      const std::string &name, const std::shared_ptr<SceneNode> parent,
      const vec3 &translation, const vec3 &rotation = vec3(0.0, 0.0, 0.0),
      const vec3 &scale = vec3(1.0, 1.0, 1.0)) {
    auto scene_node = CreateSceneNode(name, parent);
    scene_node->SetLocalTransform(translation, rotation, scale);
    return scene_node;
  }

  std::shared_ptr<SceneNode> camera_node() { return camera_node_; }
  void set_camera_node(std::shared_ptr<SceneNode> camera_node) {
    camera_node_ = camera_node;
  }

 protected:
  SceneNodeList scene_nodes_;
  std::shared_ptr<SceneNode> root_node_;
  std::shared_ptr<SceneNode> camera_node_;
  uint32_t scene_node_id_max_ = 0;
};

REGISTER_TYPE_ANNOTATION(SceneManager)

}  // namespace kuro

#endif  // CORE_SCENE_SCENE_MANAGER_H_
