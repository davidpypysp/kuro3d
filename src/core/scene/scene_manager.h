#ifndef SRC_CORE_SCENE_SCENE_MANAGER_H_
#define SRC_CORE_SCENE_SCENE_MANAGER_H_

#include <memory>
#include <vector>
#include <string>

#include "src/core/renderer/shader.h"
#include "src/core/scene/scene_node.h"

namespace kuro {

class CameraAtom;

typedef std::vector<std::shared_ptr<SceneNode>> SceneNodeList;

class SceneManager : public std::enable_shared_from_this<SceneManager> {
 public:
  SceneManager();
  void CreateDefaultScene();
  void Draw(std::shared_ptr<Shader> shader);

  void AddSceneNode(std::shared_ptr<SceneNode> scene_node);

  template <class T = SceneNode>
  std::shared_ptr<T> CreateSceneNode(
      const std::string &name,
      const std::shared_ptr<SceneNode> parent = nullptr) {
    auto scene_node = std::static_pointer_cast<SceneNode>(T::Create(name));
    scene_node->set_scene_manager(shared_from_this());
    if (parent && parent->scene_manager() == shared_from_this()) {
      parent->AddChildSceneNode(scene_node);
    }
    return std::static_pointer_cast<T>(scene_node);
  }

 protected:
  void DrawNodeTree(std::shared_ptr<SceneNode> scene_node,
                    std::shared_ptr<Shader> shader);

  SceneNodeList scene_nodes_;
  std::shared_ptr<SceneNode> root_node_;
  std::shared_ptr<CameraAtom> current_camera_;
};

}  // namespace kuro

#endif  // SRC_CORE_SCENE_SCENE_MANAGER_H_
