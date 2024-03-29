#include "src/core/base/mesh_flat_material.h"

namespace kuro {
namespace core {

std::shared_ptr<ShaderHandle> MeshFlatMaterial::shader_handle =
    std::make_shared<ShaderHandle>("mesh_flat_shader", "mesh.vert",
                                   "mesh_flat.frag");

}  // namespace core
}  //  namespace kuro