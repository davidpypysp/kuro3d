#include "src/core/renderer/shader_manager.h"

#include "src/core/base/mesh_flat_material.h"
#include "src/core/base/mesh_basic_material.h"

namespace kuro {
namespace core {

ShaderManager::ShaderManager() {}

std::shared_ptr<ShaderProgram> ShaderManager::GetShaderProgram(
    std::shared_ptr<ShaderHandle> handle) {
  return shader_map_[handle];
}

void ShaderManager::SetShaderProgram(std::shared_ptr<ShaderHandle> handle,
                                     std::shared_ptr<ShaderProgram> program) {
  shader_map_[handle] = program;
}

} /* namespace core */
}  //  namespace kuro