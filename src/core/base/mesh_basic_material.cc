#include "src/core/base/mesh_basic_material.h"

namespace kuro {
namespace core {

std::shared_ptr<ShaderHandle> MeshBasicMaterial::shader_handle =
    std::make_shared<ShaderHandle>("mesh_basic_shader", "mesh.vert",
                                   "mesh_basic.frag");

}  // namespace core
}  //  namespace kuro