#ifndef CORE_RENDERER_RENDERER_TYPE_H_
#define CORE_RENDERER_RENDERER_TYPE_H_

#include "src/math/math.h"

namespace kuro {

struct ShaderProgram {};

struct TextureHandle {};

struct GeometryHandle {};

struct Vertex {
  vec3 position;
  vec3 normal;
  vec2 tex_coords;
  vec3 tangent;
  vec3 bitangent;
};

}  // namespace kuro

#endif  // CORE_RENDERER_RENDERER_TYPE_H_
