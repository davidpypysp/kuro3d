#include "src/core/atoms/scene_atom.h"

namespace kuro {

SceneAtom::SceneAtom(const std::string &name)
    : Atom(name),
      scene_node_(std::make_shared<SceneNode>("scene_node_" + name)) {}

}  // namespace kuro
