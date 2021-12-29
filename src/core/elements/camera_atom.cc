#include "src/core/elements/camera_atom.h"

#include "src/core/engine.h"

namespace kuro {

CameraAtom::CameraAtom(const std::string& name) : SceneAtom(name) {}

std::shared_ptr<CameraAtom> CameraAtom::Create(const std::string& name) {
  auto camera_atom = std::make_shared<CameraAtom>(name);
  auto camera_pack = std::make_shared<CameraPack>();
  camera_atom->set_camera_pack(camera_pack);
  camera_atom->BindPack(camera_pack);
  return camera_atom;
}

mat4 CameraAtom::GetPerspectiveMatrix() {
  const float kRatio =
      Engine::Instance()->window_width() / Engine::Instance()->window_height();
  return camera_pack_->GetPerspectiveMatrix(kRatio);
}

mat4 CameraAtom::GetViewMatrix() {
  return camera_pack_->GetViewMatrix(translation_);
}

}  // namespace kuro
