#include "src/core/base/shader.h"
#include "src/core/engine.h"

namespace kuro {
namespace core {

Shader::Shader(const char *vertex_path, const char *fragment_path,
               const char *geometry_path) {
  shader_program_ = Engine::GetRenderAPI()->CreateShaderProgram(
      vertex_path, fragment_path, geometry_path);
}

void Shader::Use() {
  Engine::GetRenderAPI()->EnableShaderProgram(shader_program_);
}

void Shader::SetInt(const std::string &name, const int value) {
  Engine::GetRenderAPI()->SetShaderIntParam(shader_program_, name, value);
}

void Shader::SetMat4(const std::string &name, const mat4 &mat) {
  Engine::GetRenderAPI()->SetShaderMat4Param(shader_program_, name, mat);
}

}  // namespace core
}  //  namespace kuro
