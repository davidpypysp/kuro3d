#ifndef SRC_CORE_RENDERER_GEOMETRY_H_
#define SRC_CORE_RENDERER_GEOMETRY_H_

#include <vector>
#include <memory>
#include "src/core/renderer/renderer_type.h"
#include "src/core/engine.h"

namespace kuro {

class Geometry {
 public:
  Geometry() {}

  void Setup() {
    handle_ =
        Engine::GetRenderAPI()->CreateGeometryInstance(vertices_, indices_);
  }

 protected:
  std::vector<Vertex> vertices_;
  std::vector<unsigned int> indices_;
  std::shared_ptr<GeometryHandle> handle_;
};

}  // namespace kuro

#endif  // SRC_CORE_RENDERER_GEOMETRY_H_