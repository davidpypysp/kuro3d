#ifndef SRC_CORE_SCENE_CAMERA_NODE_H_
#define SRC_CORE_SCENE_CAMERA_NODE_H_

#include <memory>
#include <string>

#include "src/core/scene/scene_node.h"
#include "src/core/elements/camera_pack.h"

namespace kuro {

class CameraNode : public SceneNode {
 public:
  explicit CameraNode(const std::string& name);

  void DrawSceneNode(const std::shared_ptr<SceneNode> scene_node,
                     const std::shared_ptr<Shader> shader);

 protected:
  std::shared_ptr<CameraPack> camera_pack_;
};

}  // namespace kuro

#endif  // SRC_CORE_SCENE_CAMERA_NODE_H_
