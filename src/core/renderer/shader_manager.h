#ifndef SRC_CORE_RENDERER_SHADER_MANAGER_H_
#define SRC_CORE_RENDERER_SHADER_MANAGER_H_

#include <memory>
#include "src/core/renderer/shader.h"

namespace kuro {

class ShaderManager {
 public:
  ShaderManager();
  void Init();
  std::shared_ptr<Shader> LoadShader();

  std::shared_ptr<Shader> mesh_flat_shader() { return mesh_flat_shader_; }
  std::shared_ptr<Shader> mesh_basic_shader() { return mesh_basic_shader_; }

 protected:
  std::shared_ptr<Shader> mesh_flat_shader_;
  std::shared_ptr<Shader> mesh_basic_shader_;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_SHADER_MANAGER_H_