#ifndef SRC_CORE_RENDERER_GL_RENDER_API_H_
#define SRC_CORE_RENDERER_GL_RENDER_API_H_

#include "src/core/renderer/render_api.h"

namespace kuro {

struct GLSLShaderProgram : public ShaderProgram {
  unsigned int id;
};

struct GLGeometryHandle : public GeometryHandle {
  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo;
  unsigned int size;
};

struct GLTextureHandle : public TextureHandle {
  unsigned int id;
};

class GLRenderAPI : public RenderAPI {
 public:
  GLRenderAPI();

  void Init();
  std::shared_ptr<ShaderProgram> CreateShaderProgram(const char *vertex_path,
                                                     const char *fragment_path,
                                                     const char *geometry_path);
  void EnableShaderProgram(std::shared_ptr<ShaderProgram> program);
  void SetShaderIntParam(std::shared_ptr<ShaderProgram> program,
                         const std::string &name, const int value);
  void SetShaderMat4Param(std::shared_ptr<ShaderProgram> program,
                          const std::string &name, const mat4 &mat);
  std::shared_ptr<GeometryHandle> CreateGeometryInstance(
      const std::vector<Vertex> &vertices,
      const std::vector<unsigned int> &indices);
  void DrawMeshInstance(std::shared_ptr<GeometryHandle> handle);
  std::shared_ptr<TextureHandle> CreateTextureInstance(
      void *data, const unsigned int width, const unsigned int height,
      const TextureFormat format);
  void EnableTextureUnit(const unsigned int unit = 0,
                         std::shared_ptr<TextureHandle> handle = nullptr);

 protected:
  static constexpr GLint texture_map_[] = {GL_RED, GL_RGB, GL_RGBA};
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_GL_RENDER_API_H_
