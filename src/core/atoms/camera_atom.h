#ifndef SRC_CORE_ATOMS_CAMERA_ATOM_H_
#define SRC_CORE_ATOMS_CAMERA_ATOM_H_

#include <string>
#include <memory>

#include "src/core/atoms/atom.h"
#include "src/core/scene/scene_node.h"
#include "src/core/elements/camera_pack.h"

namespace kuro {

class CameraAtom : public Atom, public SceneNode {
 public:
  explicit CameraAtom(const std::string& name);

  static std::shared_ptr<CameraAtom> Create(const std::string& name);

 protected:
  std::shared_ptr<CameraPack> camera_pack_;
};

}  // namespace kuro

#endif  // SRC_CORE_ATOMS_CAMERA_ATOM_H_
