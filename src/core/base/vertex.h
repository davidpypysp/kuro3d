#ifndef CORE_BASE_VERTEX_H_
#define CORE_BASE_VERTEX_H_

#include "src/math/math.h"

namespace kuro {
namespace core {

struct Vertex {
  vec3 position;
  vec3 normal;
  vec2 tex_coords;
  vec3 tangent;
  vec3 bitangent;
};

}  // namespace core
}  //  namespace kuro

#endif