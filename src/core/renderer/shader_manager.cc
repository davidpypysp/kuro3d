#include "src/core/renderer/shader_manager.h"

namespace kuro {

ShaderManager::ShaderManager() {}

std::shared_ptr<ShaderProgram> ShaderManager::GetShaderProgram(
    std::shared_ptr<ShaderHandle> handle) {
  return shader_map_[handle];
}

void ShaderManager::SetShaderProgram(std::shared_ptr<ShaderHandle> handle,
                                     std::shared_ptr<ShaderProgram> program) {
  shader_map_[handle] = program;
}

}  // namespace kuro