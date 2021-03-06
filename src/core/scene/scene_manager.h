#ifndef SRC_CORE_SCENE_SCENE_MANAGER_H_
#define SRC_CORE_SCENE_SCENE_MANAGER_H_

#include <memory>
#include <vector>
#include <string>

#include "src/core/scene/scene_node.h"
#include "src/core/elements/camera_atom.h"

namespace kuro {

class CameraAtom;

typedef std::vector<std::shared_ptr<SceneNode>> SceneNodeList;

class SceneManager : public std::enable_shared_from_this<SceneManager> {
 public:
  SceneManager();
  void CreateDefaultScene();

  std::shared_ptr<SceneNode> root_node() { return root_node_; }

  template <class T = SceneNode>
  std::shared_ptr<T> CreateSceneNode(
      const std::string &name,
      const std::shared_ptr<SceneNode> parent = nullptr) {
    auto scene_node = std::static_pointer_cast<SceneNode>(T::Create(name));
    scene_node->set_id(scene_node_id_max_++);
    scene_node->set_scene_manager(shared_from_this());

    if (parent && parent->scene_manager() == shared_from_this()) {
      parent->AddChildSceneNode(scene_node);
    }
    return std::static_pointer_cast<T>(scene_node);
  }

  template <class T = SceneNode>
  std::shared_ptr<T> CreateSceneNode(const std::string &name,
                                     const std::shared_ptr<SceneNode> parent,
                                     const vec3 &translation,
                                     const vec3 &rotation = vec3(0.0, 0.0, 0.0),
                                     const vec3 &scale = vec3(1.0, 1.0, 1.0)) {
    auto scene_node = std::static_pointer_cast<SceneNode>(T::Create(name));
    scene_node->set_id(scene_node_id_max_++);
    scene_node->set_scene_manager(shared_from_this());

    if (parent) {
      parent->AddChildSceneNode(scene_node);
    }

    scene_node->SetLocalTransform(translation, rotation, scale);
    return std::static_pointer_cast<T>(scene_node);
  }

  std::shared_ptr<CameraAtom> current_camera() { return current_camera_; }

 protected:
  SceneNodeList scene_nodes_;
  std::shared_ptr<SceneNode> root_node_;
  std::shared_ptr<CameraAtom> current_camera_;
  uint32_t scene_node_id_max_ = 0;
};

}  // namespace kuro

#endif  // SRC_CORE_SCENE_SCENE_MANAGER_H_
