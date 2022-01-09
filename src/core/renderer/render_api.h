#ifndef CORE_RENDERER_RENDER_API_H_
#define CORE_RENDERER_RENDER_API_H_

#include <memory>
#include <vector>

#include "src/core/base/texture.h"
#include "src/core/base/geometry.h"
#include "src/core/renderer/shader_program.h"
#include "src/utils/type_annotation.h"

namespace kuro {

class RenderAPI {
 public:
  RenderAPI(){};

  virtual void Init() = 0;

  virtual std::shared_ptr<ShaderProgram> CreateShaderProgram(
      const char *vertex_path, const char *fragment_path,
      const char *geometry_path = nullptr) = 0;

  virtual void EnableShaderProgram(std::shared_ptr<ShaderProgram> program) = 0;

  virtual void SetShaderIntParam(std::shared_ptr<ShaderProgram> program,
                                 const std::string &name, const int value) = 0;

  virtual void SetShaderMat4Param(std::shared_ptr<ShaderProgram> program,
                                  const std::string &name, const mat4 &mat) = 0;

  virtual std::shared_ptr<GeometryHandle> CreateGeometryInstance(
      const std::vector<Vertex> &vertices,
      const std::vector<unsigned int> &indices) = 0;

  virtual void DrawMeshInstance(std::shared_ptr<GeometryHandle> handle) = 0;

  virtual std::shared_ptr<TextureHandle> CreateTextureInstance(
      void *data, const unsigned int width, const unsigned int height,
      const TextureFormat format) = 0;
  virtual void EnableTextureUnit(
      const unsigned int unit = 0,
      std::shared_ptr<TextureHandle> handle = nullptr) = 0;
};

REGISTER_TYPE_ANNOTATION(RenderAPI)

}  // namespace kuro

#endif  // CORE_RENDERER_RENDER_API_H_