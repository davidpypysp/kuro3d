#ifndef SRC_CORE_RENDERER_RENDERER_TYPE_H_
#define SRC_CORE_RENDERER_RENDERER_TYPE_H_

#include <memory>
#include <glm/glm.hpp>

namespace kuro {

struct ShaderProgram {};

struct VertexHandle {};

struct TextureHandle {};

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 tex_coords;
  glm::vec3 tangent;
  glm::vec3 bitangent;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_RENDERER_TYPE_H_
