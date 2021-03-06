#ifndef SRC_CORE_RENDERER_SHADER_H_
#define SRC_CORE_RENDERER_SHADER_H_

#include <string>
#include "src/core/renderer/render_api.h"

namespace kuro {

class Shader {
 public:
  Shader(const char *vertex_path, const char *fragment_path,
         const char *geometry_path = nullptr);

  void Use();
  // utility uniform functions
  void SetInt(const std::string &name, const int value);
  void SetMat4(const std::string &name, const mat4 &mat);

 private:
  std::shared_ptr<ShaderProgram> shader_program_;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_SHADER_H_
