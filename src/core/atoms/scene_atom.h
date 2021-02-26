#ifndef SRC_CORE_ATOMS_SCENE_ATOM_H_
#define SRC_CORE_ATOMS_SCENE_ATOM_H_

#include <string>
#include <memory>

#include "src/core/atoms/atom.h"
#include "src/core/scene/scene_node.h"

namespace kuro {

class SceneAtom : public Atom, public SceneNode {
 public:
  explicit SceneAtom(const std::string& name);
};

}  // namespace kuro

#endif  // SRC_CORE_ATOMS_SCENE_ATOM_H_
