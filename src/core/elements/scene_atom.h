#ifndef SRC_CORE_ELEMENTS_SCENE_ATOM_H_
#define SRC_CORE_ELEMENTS_SCENE_ATOM_H_

#include <string>
#include <memory>

#include "src/core/elements/atom.h"
#include "src/core/scene/scene_node.h"

namespace kuro {

class SceneAtom : public Atom, public SceneNode {
 public:
  SceneAtom(const std::string& name);

  const char* Type() const { return "SceneAtom"; }

 protected:
};

}  // namespace kuro

#endif  // SRC_CORE_ELEMENTS_SCENE_ATOM_H_
