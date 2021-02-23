#include "src/core/scene/camera_node.h"

namespace kuro {

CameraNode::CameraNode(const std::string& name) : SceneNode(name) {
  std::shared_ptr<CameraPack> camera_pack = std::make_shared<CameraPack>();
  BindPack(camera_pack);
}

}  // namespace kuro
