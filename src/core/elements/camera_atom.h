#ifndef CORE_ELEMENTS_CAMERA_ATOM_H_
#define CORE_ELEMENTS_CAMERA_ATOM_H_

#include <string>
#include <memory>

#include "src/core/elements/scene_atom.h"
#include "src/core/elements/camera_pack.h"

namespace kuro {
namespace core {

class CameraAtom : public SceneAtom {
 public:
  explicit CameraAtom(const std::string& name);

  const char* Type() const { return "CameraAtom"; }

  static std::shared_ptr<CameraAtom> Create(const std::string& name);

  void set_camera_pack(std::shared_ptr<CameraPack> camera_pack) {
    camera_pack_ = camera_pack;
  }

  std::shared_ptr<CameraPack> camera_pack() { return camera_pack_; }

  mat4 GetPerspectiveMatrix();
  mat4 GetViewMatrix();

 protected:
  std::shared_ptr<CameraPack> camera_pack_;
};

}  // namespace core
}  //  namespace kuro

#endif  // CORE_ELEMENTS_CAMERA_ATOM_H_
