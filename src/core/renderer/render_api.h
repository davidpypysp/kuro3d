#ifndef SRC_CORE_RENDERER_RENDER_API_H_
#define SRC_CORE_RENDERER_RENDER_API_H_

#include <memory>

namespace kuro {

struct ShaderProgram {};

class RenderAPI {
 public:
  RenderAPI(){};

  virtual void Init() = 0;

  virtual std::shared_ptr<ShaderProgram> CreateShaderProgram(
      const char *vertex_path, const char *fragment_path,
      const char *geometry_path = nullptr) = 0;

  virtual void EnableShaderProgram(std::shared_ptr<ShaderProgram> program) = 0;

  virtual void CreateMeshInstance() = 0;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_RENDER_API_H_