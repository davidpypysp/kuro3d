#include "src/core/elements/mesh_flat_material.h"
#include "src/core/engine.h"

namespace kuro {

MeshFlatMaterial::MeshFlatMaterial() {
  shader_ = Engine::GetShaderManager()->mesh_flat_shader();
}

void MeshFlatMaterial::Use() {}

}  // namespace kuro