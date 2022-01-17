#ifndef CORE_ELEMENTS_SCENE_ATOM_H_
#define CORE_ELEMENTS_SCENE_ATOM_H_

#include <string>
#include <memory>

#include "src/core/elements/atom.h"
#include "src/core/scene/scene_node.h"

namespace kuro {
namespace core {

class SceneAtom : public Atom, public SceneNode {
 public:
  SceneAtom(const std::string& name);

  const char* Type() const { return "SceneAtom"; }

 protected:
};

}  // namespace core
}  //  namespace kuro

#endif  // CORE_ELEMENTS_SCENE_ATOM_H_
