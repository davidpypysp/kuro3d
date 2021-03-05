#ifndef SRC_CORE_RENDERER_SHADER_H_
#define SRC_CORE_RENDERER_SHADER_H_

#include <glm/glm.hpp>
#include <string>

#include "src/core/renderer/render_api.h"

namespace kuro {

class Shader {
 public:
  // unsigned int id() const { return id_; }

  Shader(const char *vertex_path, const char *fragment_path,
         const char *geometry_path = nullptr);

  void Use();
  // utility uniform functions
  void SetInt(const std::string &name, const int value);
  void SetMat4(const std::string &name, const glm::mat4 &mat);

 private:
  // unsigned int id_;
  std::shared_ptr<ShaderProgram> shader_program_;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_SHADER_H_
