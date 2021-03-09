#ifndef SRC_CORE_ELEMENTS_CAMERA_ATOM_H_
#define SRC_CORE_ELEMENTS_CAMERA_ATOM_H_

#include <string>
#include <memory>

#include "src/core/elements/scene_atom.h"
#include "src/core/elements/camera_pack.h"
#include "src/core/renderer/shader.h"

namespace kuro {

class CameraAtom : public SceneAtom {
 public:
  explicit CameraAtom(const std::string& name);

  const char* Type() const { return "CameraAtom"; }

  static std::shared_ptr<CameraAtom> Create(const std::string& name);

  void set_camera_pack(std::shared_ptr<CameraPack> camera_pack) {
    camera_pack_ = camera_pack;
  }

  std::shared_ptr<CameraPack> camera_pack() { return camera_pack_; }

  void DrawSceneNode(SceneNode& scene_node, Shader& shader);

 protected:
  std::shared_ptr<CameraPack> camera_pack_;
};

}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_CAMERA_ATOM_H_
