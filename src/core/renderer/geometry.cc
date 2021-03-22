#include "src/core/renderer/geometry.h"
#include "src/core/engine.h"

namespace kuro {

Geometry::Geometry(const std::vector<Vertex> &vertices,
                   const std::vector<unsigned int> &indices)
    : vertices_(vertices), indices_(indices) {}

void Geometry::Setup() {
  handle_ = Engine::GetRenderAPI()->CreateGeometryInstance(vertices_, indices_);
}

}  // namespace kuro