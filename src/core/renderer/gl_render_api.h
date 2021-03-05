#ifndef SRC_CORE_RENDERER_GL_RENDER_API_H_
#define SRC_CORE_RENDERER_GL_RENDER_API_H_

#include "src/core/renderer/render_api.h"

namespace kuro {

struct GLSLShaderProgram : public ShaderProgram {
  unsigned int id;
};

class GLRenderAPI : public RenderAPI {
 public:
  GLRenderAPI();

  void Init();
  void CreateMeshInstance();
  std::shared_ptr<ShaderProgram> CreateShaderProgram(const char *vertex_path,
                                                     const char *fragment_path,
                                                     const char *geometry_path);
  void EnableShaderProgram(std::shared_ptr<ShaderProgram> program);
  void SetShaderIntParam(std::shared_ptr<ShaderProgram> program,
                         const std::string &name, const int value);
  void SetShaderMat4Param(std::shared_ptr<ShaderProgram> program,
                          const std::string &name, const glm::mat4 &mat);
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_GL_RENDER_API_H_
