#ifndef KURO_CORE_SCENE_CAMERA_NODE_H_
#define KURO_CORE_SCENE_CAMERA_NODE_H_

#include "src/core/scene/scene_node.h"
#include "src/core/elements/camera_pack.h"

namespace kuro {

class CameraNode : public SceneNode {
 public:
  CameraNode(const std::string& name);
};

}  // namespace kuro

#endif  // KURO_CORE_SCENE_CAMERA_NODE_H_