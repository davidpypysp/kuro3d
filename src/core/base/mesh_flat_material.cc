#include "src/core/base/mesh_flat_material.h"

namespace kuro {

std::shared_ptr<ShaderHandle> MeshFlatMaterial::shader_handle =
    std::make_shared<ShaderHandle>("mesh_flat_shader", "mesh.vert",
                                   "mesh_flat.frag");

std::shared_ptr<ShaderHandle> MeshFlatMaterial::GetShaderHandle() {
  return this->shader_handle;
}

}  // namespace kuro