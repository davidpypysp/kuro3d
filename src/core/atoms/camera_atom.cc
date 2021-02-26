#include "src/core/atoms/camera_atom.h"

namespace kuro {

CameraAtom::CameraAtom(const std::string& name)
    : Atom(name), SceneNode("scene_node_" + name) {}

std::shared_ptr<CameraAtom> CameraAtom::Create(const std::string& name) {
  auto camera_atom = std::make_shared<CameraAtom>(name);
  auto camera_pack = std::make_shared<CameraPack>();
  camera_atom->BindPack(camera_pack);
  return camera_atom;
}

}  // namespace kuro
