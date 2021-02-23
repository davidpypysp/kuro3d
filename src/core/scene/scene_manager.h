#ifndef KURO_CORE_SCENE_SCENE_MANAGER_H_
#define KURO_CORE_SCENE_SCENE_MANAGER_H_

#include "src/core/scene/scene_node.h"
#include "src/core/elements/camera_pack.h"
#include "src/core/renderer/shader.h"
#include "src/core/scene/camera_node.h"

#include <memory>

namespace kuro {

typedef std::vector<std::shared_ptr<SceneNode>> SceneNodeList;

class SceneManager : public std::enable_shared_from_this<SceneManager> {
 public:
  SceneManager();
  void CreateDefaultScene();
  void Draw(std::shared_ptr<Shader> shader);
  void DrawNodeTree(std::shared_ptr<SceneNode> scene_node,
                    std::shared_ptr<Shader> shader,
                    std::shared_ptr<CameraPack> camera);
  void DrawSceneNode(std::shared_ptr<SceneNode> scene_node,
                     std::shared_ptr<Shader> shader,
                     std::shared_ptr<CameraPack> camera);

  template <class SN = SceneNode>
  std::shared_ptr<SN> CreateSceneNode(const std::string &name);

  SceneNodeList scene_nodes_;
  std::shared_ptr<SceneNode> root_node_;
  std::shared_ptr<CameraNode> current_camera_node_;
};

}  // namespace kuro

#endif  // KURO_CORE_SCENE_SCENE_MANAGER_H_