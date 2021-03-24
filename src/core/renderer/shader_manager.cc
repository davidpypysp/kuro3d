#include "src/core/renderer/shader_manager.h"

namespace kuro {

ShaderManager::ShaderManager() {}

void ShaderManager::Init() {
  mesh_flat_shader_ =
      std::make_shared<Shader>("mesh_flat.vert", "mesh_flat.frag");
  mesh_basic_shader_ =
      std::make_shared<Shader>("mesh_basic.vert", "mesh_basic.frag");
}

std::shared_ptr<Shader> ShaderManager::LoadShader() { return nullptr; }

}  // namespace kuro